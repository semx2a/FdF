/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:46:09 by seozcan           #+#    #+#             */
/*   Updated: 2024/01/30 14:47:44 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
	return (1);
}

void	free_and_exit(void *ptr)
{
	free(ptr);
	exit(ft_error("fdf: ", ERR));
}

void	destroy(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->ptr);
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	img->win_ptr = NULL;
}
