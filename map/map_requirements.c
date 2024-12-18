/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_requirements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 03:15:07 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/06 19:37:54 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"

int    map_requirements(char *file_path, int *lines)
{
    int fd;
    char *str;
    int len;
    int line;
    
    len = 0;
    line = 0;
    fd = open(file_path, O_RDONLY);
    str = get_next_line(fd);
    while(str)
    {
        len = ft_strlen(str);
        free(str);
        str = get_next_line(fd);
        line += 1;
        if(len != ft_strlen(str) && str != NULL)
        {
            free(str);
            write(2, "Error: Map Invalid", 18);
            exit(1);
        }
    }
    *lines = (len - 1);
    free(str);
    return (line);
}

