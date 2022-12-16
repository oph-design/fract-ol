# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 13:35:23 by oheinzel          #+#    #+#              #
#    Updated: 2022/12/16 11:22:31 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= fract-ol

LIBFT		= libft
MLX42		= MLX42
INCLUDE		= -I include -I $(MLX42)/include
LIBS		= $(MLX42)/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -g
RM			= rm -f

GREEN		= \033[0;32m
CYAN		= \033[0;36m
WHITE		= \033[0m

#Sources

SRC_FILES	= main


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		libmlx $(NAME)

libmlx:
			@make -C $(MLX42)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) $(OBJ) $(NAME)
			@echo "$(GREEN)fract-ol compiled!$(WHITE)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(CYAN)Compiling $(WHITE): $<"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@make clean -C $(MLX42)
			@echo "$(GREEN)fract-ol object files cleaned!$(WHITE)"

fclean:		clean
			@$(RM) -f $(NAME)
			@make fclean -C $(MLX42)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(GREEN)fract-ol executable files cleaned!$(WHITE)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for fract-ol!$(WHITE)"

.PHONY:		all clean fclean re
