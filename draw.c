/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtopor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:45:43 by mtopor            #+#    #+#             */
/*   Updated: 2018/01/23 19:46:25 by mtopor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_3d **coord, t_config *conf)
{
	static t_mlx	mlx;
	t_data			i;

	init(&mlx);
	mlx.i = 0;
	i.img = mlx_new_image(mlx.mlx, WIDTHIMG, HEIGHTIMG);
	i.data = mlx_get_data_addr(i.img, &i.bpp, &i.size_line, &i.endian);
	while (mlx.i < conf->rows)
	{
		mlx.j = 0;
		while (mlx.j < conf->cols)
		{
			if (mlx.j < conf->cols - 1)
				line(coord[mlx.i][mlx.j], coord[mlx.i][mlx.j + 1], &i);
			if (mlx.i < conf->rows - 1)
				line(coord[mlx.i][mlx.j], coord[mlx.i + 1][mlx.j], &i);
			mlx.j++;
		}
		mlx.i++;
	}
	conf->tab = coord;
	conf->img = &i;
	mlx_put_image_to_window(mlx.mlx, mlx.win, i.img, 0, 0);
	mlx_key_hook(mlx.win, keys, conf);
	mlx_loop(mlx.mlx);
}
