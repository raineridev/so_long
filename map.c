/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:22:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/10 18:11:31 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void moviment_player(int keycode, s_player *player)
{
    mlx_clear_window(player->mlx, player->window);
    if (keycode == KEY_D) 
        mlx_put_image_to_window(player->mlx, player->window, player->sprite, player->y += 5, player->x);
    if (keycode == KEY_A) 
        mlx_put_image_to_window(player->mlx, player->window, player->sprite, player->y -= 5, player->x);
	if (keycode == KEY_W) 
        mlx_put_image_to_window(player->mlx, player->window, player->sprite, player->y, player->x -= 5);
    if (keycode == KEY_S) 
        mlx_put_image_to_window(player->mlx, player->window, player->sprite, player->y, player->x += 5);
}

int main(int argc, char *argv[])
{
    t_data    img;
    s_player player;
    int img_width;
    int img_height;
    int y = 0;
    void *man;
	char **map;
	int fd = 0;
	int line = 0;
    int size_line = 0;

    fd = open("maps_test/test.bef",O_RDONLY);
	printf("FD: %d\n", fd);
    line = map_requirements(argv[1], &size_line);
    map = get_map(fd, line, size_line);
    player.mlx = mlx_init();
    
    player.window = mlx_new_window(player.mlx, 1000, 800, "so_long"); // x, y
    img.img = mlx_new_image(player.mlx, 1000, 800);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);;
    player.sprite = mlx_xpm_file_to_image(player.mlx, "wallo.xpm", &img_width, &img_height);
	map_render(map, &player, size_line);
	man = mlx_xpm_file_to_image(player.mlx, "man.xpm", &img_width, &img_height);
	  
    mlx_put_image_to_window(player.mlx, player.window, player.sprite, 35, 140);
    // mlx_put_image_to_window(player.mlx, player.window, man, 43, 79);

    mlx_hook(player.window, 2, 1L << 0, moviment_player, &player);
    mlx_loop(player.mlx);
}