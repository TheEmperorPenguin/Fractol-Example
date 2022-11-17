/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtouzali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:50:56 by gtouzali          #+#    #+#             */
/*   Updated: 2022/11/16 22:01:46 by gtouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_builtin	*ft_builtin(void)
{
	static t_builtin	builtin[6] = {
	{"mandelbrot1", &mandelbrot1},
	{"mandelbrot2", &mandelbrot2},
	{"mandelbrot3", &mandelbrot3},
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
	write(1, "Wrong arg, valid arguments are:\n'mandelbrot[1-3]'\n'julia'\n", 58);
	write(1, "'burning_ship'\n", 15);
	exit (0);
}
