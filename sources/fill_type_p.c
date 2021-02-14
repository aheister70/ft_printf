/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_type_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 16:21:27 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 14:02:09 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

char		*add_prefix(char *str_arg, int field, int len)
{
	int i;

	i = 0;
	if (t_flag.minus == 1 && len < t_flag.fieldwidth)
	{
		while (str_arg[i] == ' ')
			i++;
		str_arg[i - 2] = '0';
		str_arg[i - 1] = 'x';
	}
	else
	{
		if (t_flag.minus == -1)
		{
			while (field - 2 > i)
			{
				str_arg[(field - 1) - i] = str_arg[(field - 3 - i)];
				i++;
			}
		}
		str_arg[0] = '0';
		str_arg[1] = 'x';
	}
	return (str_arg);
}

char		*fill_arg_null(int field, int len)
{
	char	*str_arg;

	str_arg = NULL;
	if (t_flag.fieldwidth < 3)
	{
		if (t_flag.minus == -1)
			t_flag.minus = 1;
		str_arg = fill_arg(" ", (field - 1), len);
	}
	else if (t_flag.fieldwidth >= 3)
		str_arg = fill_arg(" ", field, len);
	return (str_arg);
}

void		fill_type_p(void *arg)
{
	int				len;
	int				field;
	char			*argument;
	char			*str_arg;

	argument = ft_ultoa_base((unsigned long)arg);
	len = ft_ullen_base((unsigned long)arg);
	if (len > (t_flag.fieldwidth - 2))
		field = len + 2;
	else
		field = t_flag.fieldwidth;
	if (arg == NULL && t_flag.precision == 0)
		str_arg = fill_arg_null(field, len);
	else
		str_arg = fill_arg(argument, field, len);
	add_prefix(str_arg, field, len);
	ft_putstr_fd(str_arg, 1);
	t_count.printed = t_count.printed + ft_strlen(str_arg);
	free(argument);
	free(str_arg);
}
