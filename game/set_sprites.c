/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:40:56 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/16 21:32:00 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

s_sprites set_sprites(s_game game)
{
    int img_width;
    int img_height;
    s_sprites sprites;
    
    sprites.player = mlx_xpm_file_to_image(game.mlx, "assets/mans.xpm", &img_width, &img_height);
    sprites.wall = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &img_width, &img_height);
    sprites.collectable = mlx_xpm_file_to_image(game.mlx, "assets/bag33.xpm", &img_width, &img_height);
    return (sprites);
}
