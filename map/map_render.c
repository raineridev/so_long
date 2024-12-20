/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:19:39 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/20 15:57:37 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 

void    map_render(char **map, s_game *game)
{
    int y;
    int i;

    i = 0;
    y = 0;
    while (map[y] && y != 22)
    {
        while (map[y][i])
        {
            if (map[y + game->camera_pos_y][i + game->camera_pos_x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites.collectable, i * 35, y * 35);
            if (map[y + game->camera_pos_y][i + game->camera_pos_x] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites.wall, i * 35, y * 35);
            if (map[y + game->camera_pos_y][i + game->camera_pos_x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->sprites.player, i * 35, y * 35);
                game->x = (i + game->camera_pos_x) * 35;
                game->y = (y + game->camera_pos_y) * 35;
            }
            i++;
        }
        y++;
        i = 0;
    }
    printf("=\n");
}
