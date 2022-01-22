# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 21:49:59 by bkeskint          #+#    #+#              #
#    Updated: 2021/09/11 10:58:37 by bkeskint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= server
NAME1		= client

LIB_PATH	= ./libft
INCL_PATH	= /includes

LIBRARY		= libft.a

MAKE		= make

SRC			= server.c signal_handlers.c
SRC1		= client.c signal_senders.c

OBJ			= ${SRC:.c=.o}
OBJ1		= ${SRC1:.c=.o}

all:		$(LIBRARY) $(NAME) $(NAME1)

$(LIBRARY):
			$(MAKE) -C $(LIB_PATH)

$(NAME):	$(OBJ)
			$(CC) -I $(INCL_PATH) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft
			
$(NAME1):	$(OBJ1)
			$(CC) -I $(INCL_PATH) $(CFLAGS) -o $(NAME1) $(OBJ1) -L $(LIB_PATH) -lft

clean:		
			$(RM) $(OBJ) $(OBJ1)

fclean:		clean
			$(RM) $(NAME) $(NAME1)
			$(MAKE) -C $(LIB_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re