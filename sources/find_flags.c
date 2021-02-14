/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_flags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 10:24:36 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 15:43:10 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

/*
** Function to find the flags that are asigned to an argument.
*/

int			find_value_asterix(int arg, int type)
{
	if (arg < 0 && type == 1)
	{
		t_flag.minus = -1;
		arg = arg * -1;
	}
	if (arg < 0 && type == 2)
		arg = -1;
	return (arg);
}

int			find_flag_value(const char *str, int i, int type)
{
	int		n;
	int		m;
	char	*value;

	n = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	value = (char *)malloc((i - n + 1) * sizeof(char));
	m = 0;
	while (n < i)
	{
		value[m] = str[n];
		m++;
		n++;
	}
	value[m] = '\0';
	if (type == 1)
		t_flag.fieldwidth = ft_atoi(value);
	if (type == 2)
		t_flag.precision = ft_atoi(value);
	free(value);
	return (i - 1);
}

int			find_flags(const char *str, int i, va_list args)
{
	while ((str[i] != '%' && str[i] < 'A') || (str[i] > 'Z' &&
str[i] < 'a') || str[i] > 'z')
	{
		if (str[i] == '-')
			t_flag.minus = -1;
		else if (str[i] == '0' && t_flag.minus != -1)
			t_flag.zeros = 1;
		else if (str[i] > '0' && str[i] <= '9')
			i = find_flag_value(str, i, 1);
		else if (str[i - 1] != '.' && str[i] == '*')
			t_flag.fieldwidth = find_value_asterix(va_arg(args, int), 1);
		else if (str[i] == '.')
		{
			if (str[i + 1] == '*')
				t_flag.precision = find_value_asterix(va_arg(args, int), 2);
			else if (str[i + 1] >= '0' && str[i + 1] <= '9')
				i = find_flag_value(str, (i + 1), 2);
			else
				t_flag.precision = 0;
		}
		i++;
	}
	t_count.index = i;
	return (i);
}
