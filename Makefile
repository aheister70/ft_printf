# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/13 12:13:23 by aheister      #+#    #+#                  #
#    Updated: 2021/01/15 21:30:59 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
MAN_FILES		= 	ft_printf.o\
					libft/ft_atoi.o\
					libft/ft_calloc.o\
					libft/ft_memmove.o\
					libft/ft_memset.o\
					libft/ft_putchar_fd.o\
					libft/ft_putstr_fd.o\
					libft/ft_strlen.o\
					sources/fill_arg.o\
					sources/fill_blanks.o\
					sources/fill_type_c.o\
					sources/fill_type_i_d.o\
					sources/fill_type_p.o\
					sources/fill_type_percentage.o\
					sources/fill_type_s.o\
					sources/fill_type_u_x.o\
					sources/fill_zeros.o\
					sources/find_flags.o\
					sources/ft_printf_init.o\
					sources/ft_ullen_base.o\
					sources/ft_ultoa_base.o\
					sources/make_negative.o\

BONUS_FILES		=	

HEADER_FILES	=	ft_printf.h
CFLAGS			=	-Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(MAN_FILES) $(BONUS_FILES)
else
OBJ_FILES = $(MAN_FILES)
endif

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rcs $(NAME) $(OBJ_FILES)
			$(MAKE)	-C libft all

%.o:		%.c $(HEADER_FILES)
			gcc -c $(CFLAGS) -o $@ $<

bonus:
			$(MAKE)	WITH_BONUS=1 all

clean:
			rm -f $(MAN_FILES) $(BONUS_FILES)
			$(MAKE) clean -C libft

fclean: clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re bonus libft
