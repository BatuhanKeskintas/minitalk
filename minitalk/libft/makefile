# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 22:00:52 by bkeskint          #+#    #+#              #
#    Updated: 2021/08/16 22:01:37 by bkeskint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

AR		= ar rcs
RM		= rm -f

NAME	= libft.a
INCL	= libft.h

SRC		= 				ft_memset.c	ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlen.c \
						ft_strlcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcat.c \
						ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
						ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
						ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
						ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
						ft_printf.c jump.c percent.c interpret.c \
						initialize.c handle_integer.c handle_char.c handle_string.c handle_hexadecimal.c \
						handle_pointer.c handle_u_decimal.c handle_big_hexadecimal.c \
						get_next_line.c get_next_line_utils.c \

OBJ		= ${SRC:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re