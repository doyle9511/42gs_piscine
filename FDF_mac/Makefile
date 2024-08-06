# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doyle <doyle@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 09:52:15 by doyle             #+#    #+#              #
#    Updated: 2024/07/18 01:09:58 by doyle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./libft/libft.a
LIB_DIR = ./libft
CC = cc
GNL_DIR = ./get_next_line
SRC = main.c $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
RM = rm -f
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -s -C $(LIB_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L./$(LIB_DIR) -lft

%.o: %.c
	$(CC) -c $< -o $@
#	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.C
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -s -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -s -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re