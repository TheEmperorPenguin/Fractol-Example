/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:50:56 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/18 14:14:32 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_builtin	*ft_builtin(void)
{
	static t_builtin	builtin[7] = {
	{"mandelbrot1", &mandelbrot1},
	{"mandelbrot2", &mandelbrot2},
	{"mandelbrot3", &mandelbrot3},
	{"mandelbrot4", &mandelbrot4},
	{"julia", &julia},
	{"burning_ship", &ship},
	{NULL, NULL}
	};

	return (builtin);
}

void	*ft_fractal_choose(char *str)
{
	t_builtin	*search;
	int			i;

	search = ft_builtin();
	i = 0;
	while (search[i].str)
	{
		if (!ft_strcmp(str, search[i].str))
			return (search[i].f);
		i++;
	}
	return (NULL);
}

int	ft_error(void)
{
	write(1, "Wrong arg, valid arguments are:\n'mandelbrot[1-4]'\n'julia'\n", 58);
	write(1, "'burning_ship'\n", 15);
	exit (0);
}
