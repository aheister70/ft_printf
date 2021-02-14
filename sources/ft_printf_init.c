/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 19:37:03 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/14 15:32:20 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

/*
** Called with every argument to initiate the flags with their default values.
*/

void		ft_init_flags(void)
{
	t_flag.minus = 1;
	t_flag.zeros = 0;
	t_flag.fieldwidth = 0;
	t_flag.precision = -1;
	t_flag.negative = 1;
}

void		ft_init_counts(void)
{
	t_count.index = 0;
	t_count.printed = 0;
}
