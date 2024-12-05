/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_requirements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 03:15:07 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/05 05:29:53 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"

void    map_requirements(char *file_path)
{
    int fd;
    char *str;
    int len;
    len = 0;
    fd = open(file_path, O_RDONLY);
    if(fd < 0 || fd > 1024)
    {
        perror("Error");
        exit(1);
    }
    str = get_next_line(fd);
    while(str)
    {
        len = ft_strlen(str);
        free(str);
        str = get_next_line(fd);
        if(len != ft_strlen(str) && str != NULL)
        {
            write(2, "Error: Map Invalid", 18);
            exit(1);
        }
    }
}

