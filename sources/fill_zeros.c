/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_zeros.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 10:43:11 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/13 11:49:20 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

/*
** Function to fill a field for an argument with type integer with zeros.
*/

char		*fill_zeros(char *str_arg, int field)
{
	int i;

	i = 0;
	if (t_flag.minus == 1 && t_flag.precision > 0)
	{
		while (i < t_flag.precision)
		{
			str_arg[(field - 1) - i] = '0';
			i++;
		}
	}
	else if (t_flag.minus == -1 && t_flag.precision > 0)
		ft_memset(str_arg, '0', t_flag.precision);
	else if (t_flag.zeros == 1)
		ft_memset(str_arg, '0', field);
	return (str_arg);
}
