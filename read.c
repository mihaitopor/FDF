/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtopor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:51:21 by mtopor            #+#    #+#             */
/*   Updated: 2018/01/23 19:51:22 by mtopor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nr_elem(char *s)
{
	int		nr;
	int		i;

	nr = 0;
	i = 0;
	if (is_clean(s) == 0)
		error("invalid file\n");
	while (s[i])
	{
		if (i == 0 && s[i] != ' ')
			nr++;
		else if (i > 0 && s[i - 1] == ' ' && s[i] != ' ')
			nr++;
		i++;
	}
	return (nr);
}

int		getdata_fromfile(char *s, t_lc *lc, t_3d **mat)
{
	int		fd;
	char	*buff;

	buff = NULL;
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	while (get_next_line(fd, &buff) > 0)
	{
		if (lc->lin == 0)
			lc->col = nr_elem(buff);
		else if (lc->col != nr_elem(buff))
			return (0);
		lc->lin++;
	}
	close(fd);
	return (1);
}

void	init_getdata(t_lc *ij, t_lc *lc, char *buff)
{
	ij->lin = 0;
	lc->lin = 0;
	lc->col = -1;
	buff = NULL;
}

t_3d	**get_data(char *s, t_lc *lc)
{
	t_3d	**mat;
	t_lc	ij;
	int		fd;
	char	*buff;

	init_getdata(&ij, lc, buff);
	if (getdata_fromfile(s, lc, mat) == 0)
		error("invalid file");
	mat = (t_3d **)malloc(sizeof(t_3d *) * (lc->lin + 10));
	fd = open(s, O_RDONLY);
	while (ij.lin < lc->lin)
	{
		get_next_line(fd, &buff);
		mat[ij.lin] = (t_3d *)malloc(sizeof(t_3d) * (lc->col + 10));
		ij.col = 0;
		while (ij.col < lc->col)
		{
			mat[ij.lin][ij.col] = getpoint_fromstr(buff, &ij);
			ij.col++;
		}
		ij.lin++;
	}
	return (mat);
}
