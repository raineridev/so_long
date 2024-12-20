/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:47:38 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/18 07:33:05 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 

void validate_move(int keycode, s_game *game)
{
    if (keycode == KEY_W && game->map[game->y / 35 - 1][game->x / 35] != '1')
        moviment_player(game, KEY_W);
    if (keycode == KEY_S && game->map[game->y / 35 + 1][game->x / 35] != '1') 
        moviment_player(game, KEY_S);
    if (keycode == KEY_D && game->map[game->y / 35][(game->x / 35) + 1] != '1')
        moviment_player(game, KEY_D);
    if (keycode == KEY_A && game->map[game->y / 35][game->x / 35 - 1] != '1') 
        moviment_player(game, KEY_A);
}
