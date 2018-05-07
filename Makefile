# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 16:54:07 by pnarayan          #+#    #+#              #
#    Updated: 2018/04/25 21:15:12 by pnarayan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./include/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))
OBJ = $(SRC_NAME:.c=.o)
INC_NAME =	fillit.h
SRC_NAME =	read_file.c extract_pieces.c list_functions.c validity_check.c \
			map_functions.c solve.c

all: $(NAME)

$(NAME):
	@make -C $(LFT_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -L $(LFT_PATH) -lft -o $(NAME) $(SRC)

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
