# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:11:01 by hahadiou          #+#    #+#              #
#    Updated: 2023/05/09 17:57:20 by hahadiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLAGS	= -Wall -Wextra -Werror -IINC
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME	= cub3D

INC	= inc
SRC_PATH	= src
UTILS_PATH	= utils
OBJ_PATH	= obj

SRCS = main.c \
		check.c \
		init.c \
		read_map.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strtrim.c \
		ft_substr.c \
		get_next_line.c \
		ft_split.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
		ft_lstnew.c \
		my_mlx.c \
		utils.c

SRC		= $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling Utils...$(NOC)"
	@make -sC $(UTILS_PATH)
	@echo "$(YELLOW)Compiling cub3D...$(NOC)"
	@$(CC) $(FLAGS) $(MLX_FLAGS) -o $@ $^
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)/cub3d.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INC) -c -o $@ $<

clean:
	@echo "$(RED)Deleting OBJS ✔️ $(NOC)"
	@make clean -sC $(UTILS_PATH)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(RED)Deleting Binary ✔️$(NOC)"
	@make fclean -sC $(UTILS_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY:	all bonus clean fclean re
