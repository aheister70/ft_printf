/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ullen_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 10:13:04 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/15 10:01:30 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Function to calculate the length of an integer of max unsigned long.
*/

int	ft_ullen_base(unsigned long n)
{
	unsigned long	i;
	int				len;

	len = 0;
	i = n;
	while (i != 0)
	{
		i = (i / t_count.base);
		len++;
	}
	if (n <= 0)
		len = len + 1;
	return (len);
}
