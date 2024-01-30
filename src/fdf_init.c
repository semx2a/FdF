/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:33:15 by seozcan           #+#    #+#             */
/*   Updated: 2022/06/07 15:33:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	window_init(t_img *img)
{
	img->mlx_ptr = mlx_init();
	if (!img->mlx_ptr)
		free_and_exit(img->mlx_ptr);
	img->win_ptr = mlx_new_window(img->mlx_ptr, WIDTH, HEIGHT, "FdF");
	if (!img->win_ptr)
		free_and_exit(img->win_ptr);
}

void	img_init(t_img *img)
{
	img->ptr = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	if (!img->ptr)
		free_and_exit(img->ptr);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->seglen, &img->endian);
	if (!img->addr)
		free_and_exit(img->addr);
}

void	cam_init(t_img *img)
{
	img->zoom = ft_min((WIDTH / img->width / 2), (HEIGHT / img->height / 2));
	img->center[0] = WIDTH / 2;
	img->center[1] = HEIGHT / 2;
	img->x_offset = img->center[0] - (((img->width + img->height) / 2)
			* img->zoom);
	img->y_offset = img->center [1] - (((img->height - img->width) / 2)
			* img->zoom);
	img->z_div = 5;
}

void	reset(t_img *img)
{
	cam_init(img);
	mlx_destroy_image(img->mlx_ptr, img->ptr);
	img_init(img);
	render(img);
}
