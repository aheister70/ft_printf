/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_type_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 16:20:01 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 14:00:42 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int			find_field_c(int len, char *argument)
{
	int field;

	field = len;
	if (t_flag.fieldwidth > 1)
		field = t_flag.fieldwidth;
	if (t_flag.fieldwidth > 1 && argument == 0)
		field = field - 1;
	return (field);
}

char		*find_argument_c(int arg, int len)
{
	char	*argument;

	argument = 0;
	if (arg != 0)
	{
		argument = ft_calloc(len + 1, 1);
		argument = ft_memset(argument, arg, 1);
	}
	return (argument);
}

void		fill_type_c(int arg)
{
	int		len;
	int		field;
	char	*argument;
	char	*str_arg;

	len = 0;
	if (arg != 0)
		len = 1;
	argument = find_argument_c(arg, len);
	field = find_field_c(len, argument);
	str_arg = fill_arg(argument, field, len);
	if (t_flag.minus == -1 && arg == 0)
		ft_putchar_fd(arg, 1);
	ft_putstr_fd(str_arg, 1);
	if (t_flag.minus == 1 && arg == 0)
		ft_putchar_fd(arg, 1);
	if (t_flag.fieldwidth > 0)
		t_count.printed = t_count.printed + t_flag.fieldwidth;
	else
		t_count.printed = t_count.printed + 1;
	if ((t_flag.fieldwidth >= 0 && arg == 0) || arg != 0)
		free(str_arg);
	free(argument);
}
