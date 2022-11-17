/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:49:53 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/07 18:33:24 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color_put(int x, int y, t_vars vars, t_data img)
{
	double	smooth;

	smooth = vars.fractal(x, y, vars.display);
	if (smooth > vars.display.maxiter - 1)
		my_mlx_pixel_put(&img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(&img, x, y, color(21 * smooth
				+ vars.display.shift, 10 * smooth + vars.display.shift,
				50 * cos(smooth) + 130 + vars.display.shift));
}

int	ft_new_image(t_vars vars)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(vars.mlx, WIDTH * 2, HEIGHT * 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ft_color_put(x, y, vars, img);
			y++;
		}
		x++;
	}
	mlx_clear_window(vars.mlx, vars.win);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	return (0);
}
