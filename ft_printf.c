/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 17:47:33 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 09:30:43 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void		find_arg(const char *str, int i, va_list args)
{
	ft_init_flags();
	i = find_flags(str, (i + 1), args);
	t_count.type = str[i];
	if (t_count.type == 'i' || t_count.type == 'd' || t_count.type == 'u')
		t_count.base = 10;
	else if (t_count.type == 'p' || t_count.type == 'x' || t_count.type == 'X')
		t_count.base = 16;
	if (t_count.type == 'c')
		fill_type_c(va_arg(args, int));
	else if (t_count.type == 'i' || t_count.type == 'd')
		fill_type_i_d(va_arg(args, int));
	else if (t_count.type == 's')
		fill_type_s(va_arg(args, char*));
	else if (t_count.type == 'p')
		fill_type_p(va_arg(args, void*));
	else if (t_count.type == 'u')
		fill_type_u_x(va_arg(args, unsigned int));
	else if (t_count.type == 'x' || t_count.type == 'X')
		fill_type_u_x(va_arg(args, unsigned int));
	else if (t_count.type == '%')
		fill_type_percentage('%');
}

int			ft_printf(const char *str, ...)
{
	va_list		args;

	ft_init_counts();
	va_start(args, str);
	while (str[t_count.index] != '\0')
	{
		if (str[t_count.index] != '%')
		{
			ft_putchar_fd(str[t_count.index], 1);
			t_count.printed++;
		}
		else if (str[t_count.index] == '%')
			find_arg(str, t_count.index, args);
		t_count.index++;
	}
	va_end(args);
	return (t_count.printed);
}
