/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:38:42 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/10 17:36:38 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;
    int line;
    int size_line;
    char **map;
    int y = 0;
    size_line = 0;
    
    if(argc < 2 || argc > 2)
    {
        write(2, "Error: Wrong number of arguments (You need to pass 1)", 53);
        exit(1);   
    }
    fd = open(argv[1],O_RDONLY);
    if(fd < 0 || fd > 1024)
    {
        perror("Error");
        exit(1);
    }
    line = map_requirements(argv[1], &size_line);
    printf("Line: %d\nSize Line: %d\n", line, size_line);
    map = get_map(fd, line, size_line);
    while(y < line)
    {
        printf("%s", map[y++]);
        free(map[y - 1]);
    }
    free(map);
    return (0);
}
