/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:24:23 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/08 18:48:45 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"


char    **get_map(int fd, int line, int size_line)
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
    return (map);
}
