/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:08:19 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/20 15:53:15 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void moviment_player(s_game *game, int keycode)
{   
    printf("Player Pos X: %d, Y: %d\n", game->x / 35, game->y / 35);
    if (keycode == KEY_A)
    {
        if(game->size_line > 34)
        {
            game->camera_pos_x--;
            game->size_line--;
        }
        game->map[game->y / 35][game->x / 35] = '0';
        game->map[game->y / 35][game->x / 35 - 1] = 'P';
    }
    if (keycode == KEY_D)
    {
        if(game->size_line < game->total_size_line)
        {
            game->camera_pos_x++;
            game->size_line++;
        }
        game->map[game->y / 35][game->x / 35] = '0'; 
        game->map[game->y / 35][game->x / 35 + 1] = 'P';
    }
    if (keycode == KEY_S)
    {
        if (game->len_line <  game->total_lines)
        {
            game->camera_pos_y++;
            game->len_line++;
        } 
        game->map[game->y / 35][game->x / 35] = '0'; 
        game->map[game->y / 35 + 1][game->x / 35] = 'P';
    }
    if (keycode == KEY_W)
    {
        if(game->len_line > 22)
        {
            game->camera_pos_y--;
            game->len_line--;
        }
        game->map[game->y / 35][game->x / 35] = '0'; 
        game->map[game->y / 35 - 1][game->x / 35] = 'P';
    }
    printf("total_size_line: %d:\n", game->total_size_line);
    printf("total_size_line: %d:\n", game->total_lines);
    printf("size_line: %d:\n", game->size_line);
    printf("len_line: %d:\n", game->len_line);
    printf("camera_pos_x: %d:\n", game->camera_pos_x);
    printf("camera_pos_y: %d:\n", game->camera_pos_y);
    mlx_clear_window(game->mlx, game->window);
    map_render(game->map, game);
}

