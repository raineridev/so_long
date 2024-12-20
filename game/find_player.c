/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:14:19 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/18 08:25:24 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 

void find_player(s_game *game)
{
    int y;
    int x;

    x = 0;
    y = 0;
    while (game->map[y] && y != game->len_line)
    {
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P' && x > 34)
                game->camera_pos_x = x;
            x++;
        }
        y++;
        x = 0;
    }
    
}
