/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_type_u_x.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 16:24:22 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 09:18:13 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void		fill_type_u_x(unsigned int arg)
{
	int				len;
	int				field;
	char			*argument;
	char			*str_arg;

	len = 0;
	argument = 0;
	if (t_flag.zeros == 1 && t_flag.precision > -1)
		t_flag.zeros = 0;
	if (arg != 0 || (arg == 0 && t_flag.precision != 0))
	{
		argument = ft_ultoa_base((unsigned long)arg);
		len = ft_ullen_base((unsigned long)arg);
	}
	if (len >= t_flag.fieldwidth && len >= t_flag.precision)
		field = len;
	else if (t_flag.fieldwidth > t_flag.precision)
		field = t_flag.fieldwidth;
	else
		field = t_flag.precision;
	str_arg = fill_arg(argument, field, len);
	free(argument);
	ft_putstr_fd(str_arg, 1);
	t_count.printed = t_count.printed + ft_strlen(str_arg);
	free(str_arg);
}
