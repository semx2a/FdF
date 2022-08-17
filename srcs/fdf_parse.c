/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:21:22 by seozcan           #+#    #+#             */
/*   Updated: 2022/05/06 13:21:23 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	put_color(t_lst *matrix, unsigned int hex)
{
	t_node	*tmp;

	tmp = matrix->tail;
	tmp->color = hex;
}

static void	map_to_matrix(t_main *m, t_lst *matrix, t_img *img)
{
	m->i = 0;
	while (m->stab[m->i])
	{
		if (m->i == img->width && m->stab[m->i][0] == ' ')
			break ;
		else if (ft_strchr(m->stab[m->i], ','))
		{
			put_back(matrix, m->i, img->height, ft_atoi(m->stab[m->i]));
			m->j = 0;
			while (m->stab[m->i][m->j] != ',')
				m->j++;
			m->j += 3;
			put_color(matrix, ft_atoi_hexa(m->stab[m->i] + m->j));
		}
		else
			put_back(matrix, m->i, img->height, ft_atoi(m->stab[m->i]));
		m->i++;
	}
}

static void	gnl_split(t_main *m, t_img *img)
{
	m->str = get_next_line(m->fd);
	if (!m->str)
		return ;
	m->stab = ft_split(m->str, ' ');
	if (!m->stab)
		return ;
	map_to_matrix(m, img->matrix, img);
	img->height++;
}

void	map_alloc(char **av, t_main *m, t_img *img)
{
	if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
		ft_error(ERR_FILE);
	m->fd = open(av[1], O_RDONLY);
	if (m->fd == -1)
		ft_error(ERR);
	if (read(m->fd, NULL, 0) == -1)
	{
		free(m->str);
		ft_error(ERR_READ);
	}
	init_lst(img);
	gnl_split(m, img);
	img->width = ft_tablen(m->stab);
	if (m->stab[img->width - 1][0] == ' ')
		img->width--;
	while (m->str)
	{
		ft_free_stab(m->stab);
		free(m->str);
		gnl_split(m, img);
	}
	free(m->str);
	close(m->fd);
}
