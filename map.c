/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:22:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/05 02:43:36 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
	
// 	mlx_win = mlx_new_window(mlx, 1200, 800, "so_long");
// 	img.img = mlx_new_image(mlx, 1200, 800);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
	
// 	printf("\nIMG\nADDr: %s\nBITS_PER_PIXEL: %d\nLINE LENGTH: %d\nENDIAN: %d\n", img.addr, img.bits_per_pixel, img.line_length, img.endian);
// 	int j = 0;
// 	while(j < 4800)
// 	{
// 		my_mlx_pixel_put(&img, j, 70, 0x00FF0000);
// 		j++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
