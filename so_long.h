/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:44:50 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/20 13:31:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes

# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"

# define NAME "so_long"
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define WALL_SPACE 35

typedef struct sprites {
    void *player;
    void *wall;
    void *collectable;

} s_sprites;

typedef struct game {
    int y;
	int x;
    int camera_pos_x;
    int camera_pos_y;
    int collectable;
    int len_line;
    int size_line;
    int total_size_line;
    int total_lines;
    void *mlx;
    void *window;
    char **map;
    s_sprites sprites;

} s_game;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void        resize(s_game *game);
int         map_requirements(char *file_path, int *lines);
void        map_render(char **map, s_game *game);
char        **get_map(int fd, int line, int size_line, s_game *game);
s_sprites   set_sprites(s_game game);
void        validate_move(int keycode, s_game *game);
void        moviment_player(s_game *game, int keycode);
void        find_player(s_game *game);
#endif