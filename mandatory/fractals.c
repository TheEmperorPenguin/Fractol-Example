/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:34:01 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/18 13:09:08 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ship(double x, double y, t_display display)
{
	int		i;
	double	utils;
	t_dot	tmp;
	t_dot	res;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = fabs(res.x);
		res.x = x + fabs(tmp.x) - fabs(tmp.y);
		res.y = y + (fabs(utils) + fabs(utils)) * fabs(res.y);
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}

double	mandelbrot1(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = 0;
	return (utils);
}

double	mandelbrot2(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	return (utils);
}

double	mandelbrot3(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}

double	mandelbrot4(double x, double y, t_display display)
{
	t_dot	tmp;
	t_dot	res;
	double	utils;
	int		i;

	x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	utils = x;
	x = x * cos(0.01 * display.angle) - y * sin(0.01 * display.angle);
	y = y * cos(0.01 * display.angle) + utils * sin(0.01 * display.angle);
	res.x = 0;
	res.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < 50 * display.maxiter)
	{
		utils = res.x;
		res.x = x + tmp.x - tmp.y ;
		res.y = y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}

double	julia(double x, double y, t_display display)
{
	int		i;
	t_dot	tmp;
	t_dot	res;
	double	utils;

	res.x = ((x - (WIDTH / 2)) / display.zoom + display.offset_x);
	res.y = ((y - (HEIGHT / 2)) / display.zoom + display.offset_y);
	tmp.x = res.x * res.x;
	tmp.y = res.y * res.y;
	i = 0;
	while (i < display.maxiter && tmp.x + tmp.y < display.maxiter * 50)
	{
		utils = res.x;
		res.x = display.julia_x + tmp.x - tmp.y ;
		res.y = display.julia_y + (utils + utils) * res.y;
		tmp.x = res.x * res.x;
		tmp.y = res.y * res.y;
		i++;
	}
	utils = i;
	if (i != display.maxiter)
		utils = i - log(log(sqrt(tmp.x + tmp.y))) / log(2);
	return (utils);
}
