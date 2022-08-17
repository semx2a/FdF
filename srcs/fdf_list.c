/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:47 by seozcan           #+#    #+#             */
/*   Updated: 2022/05/12 15:40:06 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_lst(t_lst *lst)
{
	t_node	*tmp;

	while (lst->head)
	{
		tmp = lst->head;
		lst->head = lst->head->next;
		free(tmp);
	}
	lst->head = NULL;
	lst->tail = NULL;
	free(lst);
}

int	lst_size(t_lst *lst)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = lst->head;
	if (lst)
	{
		if (tmp)
		{
			while (tmp)
			{
				tmp = tmp->next;
				size++;
			}
			return (size);
		}
	}
	return (0);
}

void	init_lst(t_img *img)
{
	img->matrix = xmalloc(sizeof(t_lst));
	img->matrix->head = NULL;
	img->matrix->tail = NULL;
}

void	put_back(t_lst *lst, int x, int y, int z)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = 16777215;
	new->prev = lst->tail;
	new->next = NULL;
	if (lst->tail)
		lst->tail->next = new;
	else
		lst->head = new;
	lst->tail = new;
}
