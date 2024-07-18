/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:54:53 by kgrosven          #+#    #+#             */
/*   Updated: 2024/07/17 13:05:36 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_check(int iter, t_fractol *f)
{
	uint32_t	color;
	int			color_range;

	color = 0;
	color_range = f->iter / 5;
	if (iter < color_range)
		color = f->fcolor.color_1;
	else if (iter < color_range * 2)
		color = f->fcolor.color_2;
	else if (iter < color_range * 3)
		color = f->fcolor.color_3;
	else if (iter < color_range * 4)
		color = f->fcolor.color_4;
	else
		color = f->fcolor.color_5;
	mlx_put_pixel(f->img, f->x, f->y, color);
}
