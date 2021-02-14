/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:43:08 by aheister      #+#    #+#                 */
/*   Updated: 2020/11/19 12:19:15 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return (((c >= '0') && (c <= '9')) || ((c >= 'A') &&
	(c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}
