/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:28:29 by seozcan           #+#    #+#             */
/*   Updated: 2022/06/07 16:28:30 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_z_div(int keycode, t_img *img)
{
	if (keycode == PLUS_KEY || keycode == PLUS_NUM)
		img->z_div -= 0.1;
	else if (keycode == MINUS_KEY || keycode == MINUS_NUM)
		img->z_div += 0.1;
	if (img->z_div < 0.1)
		img->z_div = 0.1;
	else if (img->z_div > 10)
		img->z_div = 10;
	mlx_destroy_image(img->mlx_ptr, img->ptr);
	img_init(img);
	render(img);
}

void	ft_move(int keycode, t_img *img)
{
	if (keycode == ARROW_RIGHT)
	{
		img->x_offset += 10;
		img->center[0] += 10;
	}
	else if (keycode == ARROW_LEFT)
	{
		img->x_offset -= 10;
		img->center[0] -= 10;
	}
	else if (keycode == ARROW_DOWN)
	{
		img->y_offset += 10;
		img->center[1] += 10;
	}
	else if (keycode == ARROW_UP)
	{
		img->y_offset -= 10;
		img->center[1] -= 10;
	}
	mlx_destroy_image(img->mlx_ptr, img->ptr);
	img_init(img);
	render(img);
}

void	ft_zoom(int button, t_img *img)
{
	if (button == WHEEL_DOWN)
		img->zoom--;
	else if (button == WHEEL_UP)
		img->zoom++;
	if (img->zoom < 2)
		img->zoom = 2;
	if (img->zoom > 200)
		img->zoom = 200;
	img->x_offset = img->center[0] - (((img->width + img->height) / 2)
			* img->zoom);
	img->y_offset = img->center [1] - (((img->height - img->width) / 2)
			* img->zoom);
	mlx_destroy_image(img->mlx_ptr, img->ptr);
	img_init(img);
	render(img);
}
