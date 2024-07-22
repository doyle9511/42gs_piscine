# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doyle <doyle@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 23:52:02 by doyle             #+#    #+#              #
#    Updated: 2024/06/25 21:18:54 by doyle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = utils.c move.c sort.c main.c
SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o src

clean:
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re