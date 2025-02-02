/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:55:17 by kgrosven          #+#    #+#             */
/*   Updated: 2024/07/17 13:38:49 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	complex_square(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

void	calculate_offsets(t_fractol *f)
{
	double	range;

	range = 4.0;
	if (WIDTH > HEIGHT)
		f->off_y = ((double)HEIGHT / (double)WIDTH - 1.0) * range / 2;
	else if (HEIGHT > WIDTH)
		f->off_x = ((double)WIDTH / (double)HEIGHT - 1.0) * range / -2;
}

double	scale(double unscaled, double old_max, double new_min, double new_max)
{
	double	old_min;

	old_min = 0.0;
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}
