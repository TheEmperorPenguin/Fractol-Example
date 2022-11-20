/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:09:04 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/18 13:09:26 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
	{
		mlx_do_key_autorepeaton(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit (0);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_display	display;

	display = vars->display;
	if (keycode == 0xff56)
		display.maxiter -= 5;
	else if (keycode == 0xff55)
		display.maxiter += 5;
	else if (keycode == 0xff53)
		display.offset_x += (100.0 / display.zoom);
	else if (keycode == 0xff51)
		display.offset_x -= (100.0 / display.zoom);
	else if (keycode == 0xff52)
		display.offset_y -= 100.0 / display.zoom;
	else if (keycode == 0xff54)
		display.offset_y += 100.0 / display.zoom;
	else if (keycode == 0x20)
		display.angle += 10;
	else if (keycode == 0x31)
		vars->fractal = &mandelbrot1;
	else if (keycode == 0x32)
		vars->fractal = &mandelbrot2;
	else if (keycode == 0x33)
		vars->fractal = &mandelbrot3;
	else if (keycode == 0x34)
		vars->fractal = &mandelbrot4;
	else if (keycode == 0x35)
		vars->fractal = &julia;
	else if (keycode == 0x36)
		vars->fractal = &ship;
	if (vars->display.zoom == 0)
		vars->display.zoom++;
	vars->display = display;
	ft_new_image(*vars);
	return (0);
}
