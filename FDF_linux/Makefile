# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 09:52:15 by doyle             #+#    #+#              #
#    Updated: 2024/08/02 00:31:58 by donghwi2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CFLAGS	=	-Wall -Wextra -Werror -g
CC 		=	cc
RM		=	rm -f
LIBFT 	=	./libft/libft.a
MLX		=	./minilibx-linux/libmlx_linux.a
LIB_DIR =	./libft
SRC_DIR =	./srcs
GNL_DIR =	./get_next_line
MLX_DIR =	./minilibx-linux
SRC		=	$(SRC_DIR)/main.c\
			$(SRC_DIR)/map.c\
			$(SRC_DIR)/draw_line.c\
			$(SRC_DIR)/check.c\
			$(SRC_DIR)/mlx_utils.c\
			$(GNL_DIR)/get_next_line.c\
			$(GNL_DIR)/get_next_line_utils.c
OBJ		=	$(SRC:.c=.o)

all		: 	$(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIB_DIR)
	
$(NAME)	:	$(LIBFT) $(OBJ)
	@$(CC) $(OBJ) -L$(MLX_DIR) -I$(MLX_DIR) -L$(LIB_DIR) -lft -lmlx -lm -lz -lXext -lX11 -o $(NAME)

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.C
	@$(CC) -c $< -o $@

clean	:
	@$(RM) $(OBJ)
	@make -s -C $(LIB_DIR) clean

fclean	:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIB_DIR) fclean

re		:
	@make fclean
	@make all

.PHONY	:	all clean fclean re
