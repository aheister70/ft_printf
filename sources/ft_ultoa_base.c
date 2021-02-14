/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 11:46:39 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/15 10:00:05 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

/*
** Function to transform an integer of max unsigned long to a string.
*/

char		*ft_ultoa_base(unsigned long n)
{
	char	*nbr;
	int		len;

	len = ft_ullen_base(n);
	nbr = ft_calloc(len, 1);
	if (!nbr)
		return (0);
	if (n == 0)
		nbr[0] = '0';
	nbr[len] = '\0';
	while (n > 0)
	{
		len--;
		if ((n % t_count.base) > 9)
		{
			if (t_count.type == 'x' || t_count.type == 'p')
				nbr[len] = ((n % t_count.base) - 10) + 'a';
			else if (t_count.type == 'X')
				nbr[len] = ((n % t_count.base) - 10) + 'A';
		}
		else
			nbr[len] = n % t_count.base + '0';
		n = n / t_count.base;
	}
	return (nbr);
}
