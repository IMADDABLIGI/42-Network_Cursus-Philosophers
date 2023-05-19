# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 21:33:48 by idabligi          #+#    #+#              #
#    Updated: 2023/05/19 21:40:10 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

HEADER = philo.h

FLAGS =  -Wall -Wextra -Werror

RM = rm -f

FLS = 

FO = 

all : $(NAME)

$(NAME) : FO HEADER
	$(CC) $(FO) -o $(NAME)

%.o:%.c HEADER
	$(CC) -c $(FLAGS) $<

clean :
	$(RM) $(FO)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re