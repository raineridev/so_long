/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:22:42 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/18 07:35:58 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void resize(s_game *game)
{
    if(game->size_line * 35> 1200)
      game->size_line = 1200 / 35;
    if(game->len_line * 35 > 800)
      game->len_line = 800 / 35;
    game->window = mlx_new_window(game->mlx, game->size_line * 35, game->len_line * 35, NAME);
}
