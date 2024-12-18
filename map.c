/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:22:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/17 22:40:00 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_data    img;
    s_game game;
    int img_width;
    int img_height;
    int y = 0;
	int fd = 0;
	int line = 0;
    int size_line = 0;
    
    
    fd = open(argv[1],O_RDONLY);
    line = map_requirements(argv[1], &size_line);
    game.mlx = mlx_init();
    game.map = get_map(fd, line, size_line, &game);
    printf("size_line: %d, len_line %d\n", game.size_line * 35, game.len_line * 35);
    printf("size_line: %d, len_line %d\n", game.size_line, game.len_line);
    resize(&game);
    img.img = mlx_new_image(game.mlx, game.size_line * 35, game.len_line * 35);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    game.sprites = set_sprites(game);

    mlx_put_image_to_window(game.mlx, game.window, img.img, 0, 0);
    map_render(game.map, &game);
    printf("Y:%d, X: %d Char Map: %c\n",game.y / 35, game.x /35, game.map[game.y / 35][game.x / 35]);

    mlx_hook(game.window, 2, 1L << 0, validate_move, &game);
    mlx_loop(game.mlx);
}
