/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_blanks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 10:38:22 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 15:06:35 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_printf.h"

/*
** Function to prepare a field for argument by filling it with blanks.
*/

char		*fill_blanks(size_t field)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(field + 1);
	if (!str)
		return (0);
	while (i < field)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	if (t_count.type == 'i' || t_count.type == 'd' || t_count.type == 'u' ||
t_count.type == 'x' || t_count.type == 'X' || t_count.type == '%')
		str = fill_zeros(str, field);
	return (str);
}
