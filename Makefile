# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmoaney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 21:35:04 by rmoaney           #+#    #+#              #
#    Updated: 2021/09/14 21:35:07 by rmoaney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_C	= client.c ft_atoi.c ft_putnbr.c ft_putstr.c ft_strlen.c
SRC_S	= server.c ft_atoi.c ft_putnbr.c ft_putstr.c ft_strlen.c

OBJ_C	= $(patsubst %.c, %.o, $(SRC_C))
OBJ_S	= $(patsubst %.c, %.o, $(SRC_S))
HEADER	= minitalk.h

RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -g

%.o: %.c
			gcc $(FLAGS) -c $< -o $@

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ_S)
			gcc $(FLAGS) $^ -o $@

$(CLIENT):	$(OBJ_C)
			gcc $(FLAGS) $^ -o $@

clean:
			$(RM) $(OBJ_C)
			$(RM) $(OBJ_S)

fclean:		clean
			$(RM) $(SERVER)
			$(RM) $(CLIENT)

re:			fclean all

.PHONY:		all clean dclean re 