# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 16:11:05 by oheinzel          #+#    #+#              #
#    Updated: 2023/02/10 11:10:10 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -lglfw -L "$(HOME)/.brew/opt/glfw/lib"
NAME 		= fractol
SRC_DIR 	= src/
OBJ_DIR 	= obj/
SRC_FILES	= main utils hooks fractals
INCLUDE 	= -I include

SRC 	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
LIBFT 	= ./libft/libft.a
MLX42 	= ./MLX42/build/libmlx42.a

GREEN	= \033[0;32m
CYAN	= \033[0;36m
WHITE	= \033[0m

OBJF	= .cache_exists

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(MLX42) $(LIBFT) -o $(NAME) $(MLXFLAGS)
	@echo "$(GREEN)fractol compiled!$(WHITE)"

$(LIBFT):
	@git clone https://github.com/oph-design/libft.git
	@make -C libft

$(MLX42):
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(CYAN)Compiling $(WHITE): $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)fractol object files cleaned!$(WHITE)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)fractol executable files cleaned!$(WHITE)"

libclean:
	@rm -rf ./libft
	@rm -rf ./MLX42
	@echo "$(GREEN)Cleaned libraries for fractol!$(WHITE)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for fractol!$(WHITE)"

.PHONY: all clean fclean re
