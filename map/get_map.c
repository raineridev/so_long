/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:24:23 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/12 21:17:59 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../so_long.h"

char    **get_map(int fd, int line, int size_line, s_game *game)
{
    char **map;
    int x;
    int y;

    y = 0;
    map = malloc(line * sizeof(char **));
    if(!map)
        return (NULL);
    while(y < line)
        map[y++] = malloc(size_line * sizeof(char *));
    y = 0;
    while(y < line) 
        map[y++] = get_next_line(fd);
    game->len_line = line;
    game->size_line = size_line;
    return (map);
}
