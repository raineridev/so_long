/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:19:39 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/18 05:21:42 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 

void    map_render(char **map, s_game *game)
{
    int y = 0;
    int i = 0;
    
    // y += test;
    printf("%d\n", i);
    while (map[y] && y != game->len_line)
    {
        while (map[y][i])
        {
            // printf("Map Char: %c, Y: %d, I: %d\n", map[y][i], y, i);
            if (map[y][i] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites.collectable, i * 35, y * 35);
            if (map[y][i] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites.wall, i * 35, y * 35);
            if (map[y][i] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->sprites.player, i * 35, y * 35);
                game->x = i * 35;
                game->y = y * 35;
            }
            i++;
        }
        y++;
        i = 0;
    }  
}
