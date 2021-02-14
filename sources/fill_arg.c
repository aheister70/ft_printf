/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_arg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 14:00:16 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 15:06:45 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

/*
** Function to fill the field with the argument.
*/

char		*fill_arg(char *arg, int field, int len)
{
	int		i;
	char	*str_arg;

	i = 0;
	str_arg = fill_blanks(field);
	if (t_flag.minus == 1)
	{
		while (i < len)
		{
			str_arg[(field - 1) - i] = arg[(len - 1) - i];
			i++;
		}
	}
	else if (t_flag.minus == -1)
	{
		while (len < t_flag.precision && i < len)
		{
			str_arg[(t_flag.precision - 1) - i] = arg[(len - 1) - i];
			i++;
		}
		if (len >= t_flag.precision)
			ft_memmove(str_arg, arg, len);
	}
	return (str_arg);
}
