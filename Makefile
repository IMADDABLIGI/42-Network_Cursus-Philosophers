# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 21:33:48 by idabligi          #+#    #+#              #
#    Updated: 2023/06/03 14:39:36 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
HEADER = philo.h
FLAGS =  -Wall -Wextra -Werror
RM = rm -f
COLOUR_GREEN=\033[1;32m
COLOUR_RESET= \033[1;0m
COLOUR_RED=\033[1;31m


FLS = threads philo_utils lst_functions ft_parsing ft_execute\

FO = $(FLS:=.o)

all : $(NAME)

$(NAME) : $(FO) $(HEADER)
	$(CC)  $(FLAGS) $(FO) -o $(NAME)
	@echo  "$(COLOUR_GREEN)--->[mandatory part successfully created ✅]<---$(COLOUR_RESET)"

%.o:%.c $(HEADER)
	$(CC) -c $(FLAGS) $<

clean :
	$(RM) $(FO)
	@echo "$(COLOUR_RED)--->[obj file deleted successfully ✅]<---$(COLOUR_RESET)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(COLOUR_RED)--->[programs deleted successfully ✅]<---$(COLOUR_RESET)"

re : fclean all

.PHONY : all clean fclean re