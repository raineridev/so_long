/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:04 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/10 13:54:56 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.c"

void moviment_player(int keybind, s_player *player)
{
    if (keycode == KEY_D) 
        mlx_put_image_to_window(player->lib, player->win, player->sprite, player->y += 3, player->x);
    if (keycode == KEY_A) 
        mlx_put_image_to_window(player->lib, player->win, player->sprite, player->y -= 3, player->x);
	if (keycode == KEY_W) 
        mlx_put_image_to_window(player->lib, player->win, player->sprite, player->y, player->x -= 3);
    if (keycode == KEY_S) 
        mlx_put_image_to_window(player->lib, player->win, player->sprite, player->y, player->x += 3);
	printf("Y: %d, X: %d\n", player->y, player->x);
}