/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_type_i_d.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 16:28:14 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 13:57:50 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

int			find_field_i(int len)
{
	int	field;

	if (len >= t_flag.fieldwidth && len >= t_flag.precision)
		field = len;
	else if (t_flag.fieldwidth > t_flag.precision)
		field = t_flag.fieldwidth;
	else if (t_flag.fieldwidth <= t_flag.precision)
		field = t_flag.precision;
	if (t_flag.negative == -1 &&
(t_flag.fieldwidth <= t_flag.precision || field == len))
		field = field + 1;
	return (field);
}

char		*find_argument_i(int arg)
{
	char	*argument;

	if (arg != 0 || (arg == 0 && t_flag.precision != 0))
	{
		if (arg == INT_MIN)
			argument = ft_ultoa_base(2147483648);
		else
			argument = ft_ultoa_base((unsigned long)arg);
	}
	else
		argument = 0;
	return (argument);
}

void		fill_type_i_d(int arg)
{
	int				len;
	int				field;
	char			*argument;
	char			*str_arg;

	len = 0;
	if (arg < 0)
		t_flag.negative = -1;
	if (arg != INT_MIN)
		arg = arg * t_flag.negative;
	argument = find_argument_i(arg);
	if ((arg != 0 && arg != INT_MIN) || (arg == 0 && t_flag.precision != 0))
		len = ft_ullen_base((unsigned long)arg);
	if (arg == INT_MIN)
		len = ft_ullen_base(2147483648);
	field = find_field_i(len);
	str_arg = fill_arg(argument, field, len);
	if (t_flag.negative == -1)
		make_negative(str_arg, field);
	ft_putstr_fd(str_arg, 1);
	t_count.printed = t_count.printed + ft_strlen(str_arg);
	free(argument);
	free(str_arg);
}
