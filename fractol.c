/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:55:02 by kgrosven          #+#    #+#             */
/*   Updated: 2024/07/17 13:17:53 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	f.inted = 0;
	if (ac == 1)
	{
		intro_msg(&f);
		exit(0);
	}
	check_args(&f, av, ac);
	init(&f);
	draw_fractal(&f);
	mlx_scroll_hook(f.mlx, &scrollhook, &f);
	mlx_loop_hook(f.mlx, &drawhook, &f);
	mlx_key_hook(f.mlx, &keyhook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
