/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:53:35 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/18 13:09:52 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	display_init(void)
{
	t_display	display;

	display.angle = 0;
	display.offset_x = 0;
	display.offset_y = 0;
	display.zoom = 200;
	display.maxiter = 40;
	display.shift = 0;
	display.julia_x = 0;
	display.julia_y = 0;
	return (display);
}

t_display	ft_julia_init(char *x, char *y)
{
	t_display	display;

	display.angle = 0;
	display.offset_x = 0;
	display.offset_y = 0;
	display.zoom = 200;
	display.maxiter = 40;
	display.shift = 0;
	display.julia_x = atof(x);
	display.julia_y = atof(y);
	return (display);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	vars.fractal = ft_fractal_choose(argv[1]);
	if (!vars.fractal)
		ft_error();
	if (argc == 4 && !ft_strcmp("julia", argv[1]))
		vars.display = ft_julia_init(argv[2], argv[3]);
	else if (argc != 2)
		ft_error();
	if (argc == 2)
		vars.display = display_init();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	mlx_do_key_autorepeatoff(vars.mlx);
	vars.win = mlx_new_window(vars.mlx, WIDTH * 2, HEIGHT * 2, "gtouzali");
	if (!vars.win)
		return (0);
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, cross, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
