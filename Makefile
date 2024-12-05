# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 22:07:05 by mraineri          #+#    #+#              #
#    Updated: 2024/12/05 02:43:49 by mraineri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS :=  -I/usr/include -Imlx_linux -O3 # -Wall -Wextra -Werror

# Source and Object Files
FILES := main.c
OBJ_DIR := objects
OBJECTS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Library Information
MLX := mlx_linux

# Build Rules
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -L$(MLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(NAME)

fclean: clean

re: fclean all