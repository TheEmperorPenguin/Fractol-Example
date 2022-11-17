/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:05:23 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/07 17:13:00 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	handle_no_event(t_vars *vars)
{
	vars->display.shift += 1;
	ft_new_image(*vars);
	return (0);
}

void	fmlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	fmlx_pixel_put(data, x * 2, y * 2, color);
	fmlx_pixel_put(data, x * 2 + 1, y * 2, color);
	fmlx_pixel_put(data, x * 2, y * 2 + 1, color);
	fmlx_pixel_put(data, x * 2 + 1, y * 2 + 1, color);
}

int	color(int r, int g, int b)
{
	int	rgb;

	b = b % 512;
	if (b > 255)
		b = 255 - b % 256;
	r = r % 512;
	if (r > 255)
		r = 255 - r % 256;
	g = g % 512;
	if (g > 255)
		g = 255 - g % 256;
	rgb = ((r % 256) * 256 * 256) + ((g % 256) * 256) + (b % 256);
	return (rgb);
}
