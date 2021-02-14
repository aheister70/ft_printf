/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_type_percentage.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 20:46:00 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 15:42:11 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void		fill_type_percentage(int arg)
{
	int		len;
	int		field;
	char	*argument;
	char	*str_arg;

	len = 1;
	if (t_flag.zeros == 1 && t_flag.minus == -1)
		t_flag.zeros = 0;
	argument = ft_calloc(len + 1, 1);
	argument = ft_memset(argument, arg, 1);
	field = len;
	if (t_flag.precision > -1)
		t_flag.precision = -1;
	if (t_flag.fieldwidth > len)
		field = t_flag.fieldwidth;
	str_arg = fill_arg(argument, field, len);
	ft_putstr_fd(str_arg, 1);
	if (t_flag.fieldwidth > 0)
		t_count.printed = t_count.printed + t_flag.fieldwidth;
	else
		t_count.printed = t_count.printed + 1;
	free(argument);
	free(str_arg);
}
