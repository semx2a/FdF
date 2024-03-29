/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:54:42 by seozcan           #+#    #+#             */
/*   Updated: 2024/01/30 13:21:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	print_coordinate(t_coordinate *coordinate)
{
	t_coordinate	*tmp;

	tmp = coordinate;
	if (tmp)
	{
		while (tmp)
		{
			ft_printf("[%d]\n", tmp->z);
			tmp = tmp->next;
		}
	}
}

void	print_lst(t_lst *matrix)
{
	t_coordinate	*tmp;

	tmp = matrix->head;
	while (tmp)
	{
		ft_printf("\033[0;31m[%d]\t\033[0;32m[%d]\t\033[0;33m[%d]\t\033[0;34m[%d]\n",
			tmp->x, tmp->y, tmp->z, tmp->color);
		tmp = tmp->next;
	}
	ft_printf("\033[0;31m[x]\t\033[0;32m[y]\t\033[0;33m[z]\t\033[0;34m[color]\n");
}

void	print_address(t_lst *stack)
{
	t_coordinate	*tmp;

	tmp = stack->head;
	if (tmp)
	{
		while (tmp)
		{
			ft_printf("coordinate->nb = [%d]\t  | ", tmp->z);
			ft_printf("content address = [%p]   | ", &tmp->z);
			ft_printf("list address = [%p]\n", &tmp);
			tmp = tmp->next;
		}
	}
}
