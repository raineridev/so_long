/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:22:42 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/17 22:30:46 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void resize(s_game *game)
{
   int size_line = game->size_line * 35;
   int len_line = game->len_line * 35;
    if(size_line  > 1200)
      size_line = 1200;
    if(len_line > 800)
      len_line = 800;
    game->window = mlx_new_window(game->mlx, size_line, len_line, NAME);
}
