/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:17:59 by seozcan           #+#    #+#             */
/*   Updated: 2024/01/30 13:21:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	in_window(int x, int y)
{
	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIDTH - 1)
		return (0);
	return (1);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (in_window(x, y) == 1)
	{
		pixel = img->addr + (y * img->seglen + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	drawline_x(t_map *map, t_img *img, t_coordinate *ext1)
{	
	int		i;

	i = 0;
	while (i <= map->sx)
	{
		put_pixel(img, map->x1, map->y1, ext1->color);
		i++;
		map->x1 += map->xinc;
		map->ex -= map->dy;
		if (map->ex < 0)
		{
			map->y1 += map->yinc;
			map->ex += map->dx;
		}
	}
}

void	drawline_y(t_map *map, t_img *img, t_coordinate *ext1)
{	
	int		i;

	i = 0;
	while (i <= map->sy)
	{
		put_pixel(img, map->x1, map->y1, ext1->color);
		i++;
		map->y1 += map->yinc;
		map->ey -= map->dx;
		if (map->ey < 0)
		{
			map->x1 += map->xinc;
			map->ey += map->dy;
		}
	}
}
