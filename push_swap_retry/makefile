# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 19:59:36 by mboudrio          #+#    #+#              #
#    Updated: 2023/12/03 05:54:59 by mboudrio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRC_FILES = push_swap.c  push_swap_tools.c handling_errors.c push_swap_tools_1.c actions.c  actions_1.c actions_2.c sorting_algorithm.c sorting_100_reverse.c  sorting_100.c
BONUS_FILES = checker.c checker_tools.c checker_tools1.c checker_actions.c checker_actions1.c  checker_actions2.c get_next_line.c get_next_line_tools.c 
OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(BONUS): $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) -o $(BONUS)
	
clean:
	$(RM) $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re:			 $(NAME) 

rebonus:	 $(BONUS) 

