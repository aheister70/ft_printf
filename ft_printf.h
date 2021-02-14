/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 14:52:57 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/17 15:06:59 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>

struct				s_flags
{
	int				minus;
	int				zeros;
	int				fieldwidth;
	int				precision;
	int				negative;
}					t_flag;

struct				s_counts
{
	int				index;
	int				printed;
	int				type;
	int				base;
}					t_count;

char				*fill_arg(char *arg, int field, int len);
char				*fill_blanks(size_t field);
void				fill_type_c(int arg);
void				fill_type_i_d(int arg);
void				fill_type_p(void *arg);
void				fill_type_percentage(int arg);
void				fill_type_s(char *arg);
void				fill_type_u_x(unsigned int arg);
char				*fill_zeros(char *str_arg, int field);
int					find_flags(const char *str, int i, va_list args);
void				ft_init_counts(void);
void				ft_init_flags(void);
int					ft_printf(const char *str, ...);
char				*make_negative(char *str_arg, int field);
int					ft_ullen_base(unsigned long n);
char				*ft_ultoa_base(unsigned long n);
#endif
