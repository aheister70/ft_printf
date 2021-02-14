/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_type_s.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 16:18:36 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 15:42:58 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void		fill_type_s(char *arg)
{
	int		len;
	int		field;
	char	*str_arg;

	if (arg == 0)
		arg = "(null)";
	len = ft_strlen(arg);
	if (t_flag.precision >= 0 && t_flag.precision < len)
		len = t_flag.precision;
	else
		t_flag.precision = -1;
	if (len > t_flag.fieldwidth && t_flag.negative == -1)
		field = len + 1;
	else if (len > t_flag.fieldwidth && t_flag.negative == 1)
		field = len;
	else if (t_flag.fieldwidth > t_flag.precision)
		field = t_flag.fieldwidth;
	else if (t_flag.fieldwidth > t_flag.precision && t_flag.negative == -1)
		field = t_flag.fieldwidth + 1;
	else
		field = t_flag.precision;
	str_arg = fill_arg(arg, field, len);
	ft_putstr_fd(str_arg, 1);
	t_count.printed = t_count.printed + ft_strlen(str_arg);
	free(str_arg);
}
