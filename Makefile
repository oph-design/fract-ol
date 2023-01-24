# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 16:11:05 by oheinzel          #+#    #+#              #
#    Updated: 2023/01/24 18:38:36 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -g -Wall -Werror -Wextra
MLXFLAGS	= -lglfw -L "$(HOME)/.brew/opt/glfw/lib"
NAME 		= fractol
SRC_DIR 	= src/
OBJ_DIR 	= obj/
SRC_FILES	= main utils hooks fractals
INCLUDE 	= -I include

SRC 	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
LIBFT 	= ./libft/libft.a
MLX42 	= ./MLX42/libmlx42.a

GREEN	= \033[0;32m
CYAN	= \033[0;36m
WHITE	= \033[0m

OBJF	= .cache_exists

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(INCLUDE) $(MLX42) $(LIBFT) -o $(NAME) $(MLXFLAGS)
	@echo "$(GREEN)fract-ol compiled!$(WHITE)"

$(LIBFT):
	@make -C libft

$(MLX42):
	@make -C MLX42

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(CYAN)Compiling $(WHITE): $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)fract-ol object files cleaned!$(WHITE)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)fract-ol executable files cleaned!$(WHITE)"

libclean:
	@rm -rf ./libft
	@rm -rf ./MLX42
	@echo "$(GREEN)Cleaned libraries for fract-ol!$(WHITE)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for fract-ol!$(WHITE)"

.PHONY: all clean fclean re
