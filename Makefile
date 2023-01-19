# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 16:11:05 by oheinzel          #+#    #+#              #
#    Updated: 2023/01/19 16:19:26 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -lglfw -L "$(HOME)/.brew/opt/glfw/lib"
NAME 		= fract-ol
SRC_DIR 	= src/
#OBJ_DIR 	= obj/
SRC_FILES	= main param
INCLUDE 	= -I include

SRC 	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 	= $(addprefix $(SRC_DIR), $(addsuffix .o, $(SRC_FILES)))
#OBJF	= .cache_exists
LIBFT 	= ./libft/libft.a
MLX42 	= ./MLX42/libmlx42.a

GREEN	= \033[0;32m
CYAN	= \033[0;36m
WHITE	= \033[0m

all: $(NAME)

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(INCLUDE) $(MLX42) $(LIBFT) -o $(NAME) $(MLXFLAGS)
	@echo "$(GREEN)fract-ol compiled!$(WHITE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c #| $(OBJF)
	@echo "$(CYAN)Compiling $(WHITE): $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

#$(OBJF):
#	@mkdir -p $(OBJ_DIR)

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
	@make -C LeakSanitizer

$(LIBFT):
	@if [ ! -d "libft" ]; then git clone https://github.com/oph-design/libft.git: fi
	@make -C libft

$(MLX42):
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && make

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)fract-ol object files cleaned!$(WHITE)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)fract-ol executable files cleaned!$(WHITE)"

libclean:
	@rm -rf ./libft
	@rm -rf ./MLX42
	@echo "$(GREEN)Cleaned and rebuilt everything for fract-ol!$(WHITE)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for fract-ol!$(WHITE)"

.PHONY: all clean fclean re
