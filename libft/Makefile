# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aheister <aheister@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 11:41:15 by aheister      #+#    #+#                  #
#    Updated: 2021/01/13 16:24:55 by aheister      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
MAN_FILES		= 	ft_atoi.o\
					ft_bzero.o\
					ft_calloc.o\
					ft_isalnum.o\
					ft_isalpha.o\
					ft_isascii.o\
					ft_isdigit.o\
					ft_isprint.o\
					ft_itoa.o\
					ft_memccpy.o\
					ft_memchr.o\
					ft_memcmp.o\
					ft_memcpy.o\
					ft_memmove.o\
					ft_memset.o\
					ft_putchar_fd.o\
					ft_putendl_fd.o\
					ft_putnbr_fd.o\
					ft_putstr_fd.o\
					ft_split.o\
					ft_strchr.o\
					ft_strdup.o\
					ft_strjoin.o\
					ft_strlcat.o\
					ft_strlcpy.o\
					ft_strlen.o\
					ft_strmapi.o\
					ft_strncmp.o\
					ft_strnstr.o\
					ft_strrchr.o\
					ft_strtrim.o\
					ft_substr.o\
					ft_tolower.o\
					ft_toupper.o\

HEADER_FILES	=	libft.h
CFLAGS			=	-Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(MAN_FILES) $(BONUS_FILES)
else
OBJ_FILES = $(MAN_FILES)
endif

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rcs $(NAME) $(OBJ_FILES)

%.o: 		%.c $(HEADER_FILES)
			gcc -c $(CFLAGS) -o $@ $<

bonus:
			$(MAKE) WITH_BONUS=1 all

clean:
			rm -f $(MAN_FILES) $(BONUS_FILES)

fclean: clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re bonus
