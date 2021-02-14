/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_negative.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 10:48:42 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/13 11:48:47 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Function to add a '-' sign to a negative integer.
*/

char		*make_negative(char *str_arg, int field)
{
	int i;

	i = 0;
	if (t_flag.minus == 1)
	{
		if (t_flag.zeros == 0 || (t_flag.precision > 0 &&
t_flag.precision <= t_flag.fieldwidth))
		{
			while (str_arg[i] == ' ')
				i++;
			str_arg[i - 1] = '-';
		}
		else
			str_arg[0] = '-';
	}
	else if (t_flag.minus == -1)
	{
		while (field - 1 > i)
		{
			str_arg[(field - 1) - i] = str_arg[(field - 2 - i)];
			i++;
		}
		str_arg[0] = '-';
	}
	return (str_arg);
}
