/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:19:39 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/10 17:46:03 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 

void    map_render(char **map, s_player *player, int size_line)
{
    int y = 0;
    int size = 0;
    while(10 > y++)
        mlx_put_image_to_window(player->mlx, player->window, player->sprite, size += 35, 0);
}
