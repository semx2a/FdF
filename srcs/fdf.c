/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:18:55 by seozcan           #+#    #+#             */
/*   Updated: 2022/05/06 13:18:56 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_main	m;
	t_img	img;

	if (ac != 2)
		return (0);
	m = (t_main){0};
	img = (t_img){0};
	map_alloc(av, &m, &img);
	window_init(&img);
	img_init(&img);
	cam_init(&img);
	mlx_loop_hook(img.mlx_ptr, &render, &img);
	controls(&img);
	mlx_loop(img.mlx_ptr);
	destroy(&img);
	free_lst(img.matrix);
	free(img.mlx_ptr);
	return (0);
}
