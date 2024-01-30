/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:56:07 by seozcan           #+#    #+#             */
/*   Updated: 2024/01/30 13:21:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	xy_increment(int a, int b)
{
	if (a > b)
		return (-1);
	return (1);
}

static void	projection(t_img *img, t_coordinate *ext1, t_coordinate *ext2)
{
	t_map	map;

	map = (t_map){0};
	map.x1 = ((ext1->x + ext1->y) * img->zoom) + img->x_offset;
	map.y1 = ((ext1->y - ext1->x) * img->zoom / 2) - (ext1->z
			* (img->zoom / img->z_div)) + img->y_offset;
	map.x2 = ((ext2->x + ext2->y) * img->zoom) + img->x_offset;
	map.y2 = ((ext2->y - ext2->x) * img->zoom / 2) - (ext2->z
			* (img->zoom / img->z_div)) + img->y_offset;
	map.ex = abs(map.x2 - map.x1);
	map.ey = abs(map.y2 - map.y1);
	map.dx = 2 * map.ex;
	map.dy = 2 * map.ey;
	map.sx = map.ex;
	map.sy = map.ey;
	map.xinc = xy_increment(map.x1, map.x2);
	map.yinc = xy_increment(map.y1, map.y2);
	if (map.sx >= map.sy)
		drawline_x(&map, img, ext1);
	else
		drawline_y(&map, img, ext1);
}

int	render(t_img *img)
{
	img->tmp_a = img->matrix->head;
	while (img->tmp_a && img->tmp_a->y < img->height)
	{
		img->hold = img->tmp_a;
		while (img->tmp_a && img->tmp_a->x < img->width - 1)
		{
			projection(img, img->tmp_a, img->tmp_a->next);
			img->tmp_a = img->tmp_a->next;
		}
		img->tmp_b = img->tmp_a->next;
		img->tmp_a = img->hold;
		while (img->tmp_a && img->tmp_b && img->tmp_a->x < img->width - 1)
		{
			projection(img, img->tmp_a, img->tmp_b);
			img->tmp_a = img->tmp_a->next;
			img->tmp_b = img->tmp_b->next;
		}
		if (img->tmp_a && img->tmp_b)
			projection(img, img->tmp_a, img->tmp_b);
		img->tmp_a = img->tmp_a->next;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->ptr, 0, 0);
	return (0);
}
