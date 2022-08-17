/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:55:07 by seozcan           #+#    #+#             */
/*   Updated: 2022/05/12 15:55:21 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(t_img *img)
{
	mlx_loop_end(img->mlx_ptr);
	return (0);
}

int	ft_keycode(int keycode, t_img *img)
{
	if (keycode == XK_Escape)
		close_window(img);
	else if (keycode == MINUS_NUM || keycode == MINUS_KEY
		|| keycode == PLUS_NUM || keycode == PLUS_KEY)
		ft_z_div(keycode, img);
	else if (keycode == ARROW_DOWN || keycode == ARROW_LEFT
		|| keycode == ARROW_RIGHT || keycode == ARROW_UP)
		ft_move(keycode, img);
	else if (keycode == ZERO_KEY || keycode == ZERO_NUM)
		reset(img);
	return (0);
}

int	ft_mouse(int button, int x, int y, t_img *img)
{
	(void)x;
	(void)y;
	if (button == WHEEL_UP || button == WHEEL_DOWN)
		ft_zoom(button, img);
	return (0);
}

void	controls(t_img *img)
{
	mlx_key_hook(img->win_ptr, ft_keycode, img);
	mlx_mouse_hook(img->win_ptr, ft_mouse, img);
	mlx_hook(img->win_ptr, 17, 0, close_window, img);
}
