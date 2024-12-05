/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:38:42 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/05 02:52:13 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int fd;

    fd = open("maps_test/test.bef",O_RDONLY);
    if(fd < 0 || fd > 1024)
    {
        perror("Error");
        exit(1);
    }
    
    return (0);
}