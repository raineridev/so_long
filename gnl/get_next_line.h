/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:53:34 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/05 04:39:30 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Includes

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Define
# define BUFFER_SIZE 42
# define OPEN_MAX 1024

// Functions: 

/// Int Retun's

int	    ft_have_breakline(char *buffer);
int	    ft_strlen(char *str);

/// Char Retun's
char    *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2);
char    *ft_strcut(char *line, char *buffer);
#endif