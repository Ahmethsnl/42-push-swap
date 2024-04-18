# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 13:33:13 by ahmsanli          #+#    #+#              #
#    Updated: 2024/04/18 20:06:04 by ahmsanli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = utils.c move.c sort.c main.c
SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft
	@echo Done
	@echo push_swap created

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC) -I./$(LIBFT_DIR)
	@mv *.o src

clean:	
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean
	@echo object files deleted

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@echo push_swap deleted

re:	fclean all clean

.PHONY: all clean fclean re