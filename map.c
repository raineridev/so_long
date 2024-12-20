/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:22:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/18 08:17:37 by mraineri         ###   ########.fr       */
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
    resize(&game);
    img.img = mlx_new_image(game.mlx, game.size_line * 35, game.len_line * 35);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    game.sprites = set_sprites(game);
    game.total_size_line = (ft_strlen(game.map[0]) - 1);
    mlx_put_image_to_window(game.mlx, game.window, img.img, 0, 0);
    find_player(&game);
    map_render(game.map, &game);
    mlx_hook(game.window, 2, 1L << 0, validate_move, &game);
    mlx_loop(game.mlx);
}
