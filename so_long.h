/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:44:50 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/10 17:41:59 by mraineri         ###   ########.fr       */
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

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define FOLDER_PLAYER "./assets/"

typedef struct players {
    int y;
	int x;
    void *mlx;
    void *window;
    void *sprite;
} s_player;

typedef struct moviment {
    
} moviment; 
int     map_requirements(char *file_path, int *lines);
void    map_render(char **map, s_player *player, int size_line);
char    **get_map(int fd, int line, int size_line);

#endif