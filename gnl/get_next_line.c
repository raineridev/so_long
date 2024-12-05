/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:20:11 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/25 15:27:05 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE + 1];
    int             bits;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
        return (NULL);
    line = NULL;
    if(buffer[0] != '\0')
        line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
    while (ft_have_breakline(line) == -1)
    {  
        bits = read(fd, buffer, BUFFER_SIZE);
        buffer[bits] = '\0';
        if(bits == 0)
            return (line);
        if(bits < 0)
            return(free(line), NULL);
        line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
    }
    return (ft_strcut(line, buffer));
}