# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 22:07:05 by mraineri          #+#    #+#              #
#    Updated: 2024/12/05 04:38:41 by mraineri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -I/usr/include -Imlx_linux -O3 # -Wall -Wextra -Werror

# Source and Object Files
GNL_FILES := gnl/get_next_line_utils.c gnl/get_next_line.c
FILES := main.c maps/map_requirements.c $(GNL_FILES)
OBJ_DIR := objects
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.c=.o))) # Remove o path original

# Library Information
MLX := mlx_linux

# Build Rules
SRCS := $(FILES)
VPATH := $(dir $(SRCS)) # Diretórios de onde os arquivos fontes podem ser encontrados

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
