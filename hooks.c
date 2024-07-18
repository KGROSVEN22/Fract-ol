/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:55:12 by kgrosven          #+#    #+#             */
/*   Updated: 2024/07/17 13:36:04 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhook(mlx_key_data_t keydata, void *f)
{
	t_fractol	*nf;

	nf = f;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ene(nf);
}

void	scrollhook(double xdelta, double ydelta, void *f)
{
	t_fractol	*nf;

	nf = f;
	(void)xdelta;
	if (ydelta < 0)
	{
		nf->zoom *= 0.95;
	}
	else if (ydelta > 0)
	{
		nf->zoom *= 1.05;
	}
	draw_fractal(nf);
}
