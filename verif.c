/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtopor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:51:41 by mtopor            #+#    #+#             */
/*   Updated: 2018/01/23 19:51:42 by mtopor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err(char n)
{
	write(1, &n, 1);
	write(1, "Map Error\n", 11);
	exit(1);
}

void	v_col(char *t)
{
	int	i;
	int	c;
	int	g;

	i = 0;
	g = 0;
	c = 0;
	while (t[i])
	{
		c = 0;
		while (t[i] != '\n' && t[i])
		{
			if (t[i] != ' ' &&
					(t[i + 1] == ' ' || t[i + 1] == '\n' || t[i + 1] == '\0'))
				c++;
			i++;
		}
		if (g == 0)
			g = c;
		else if (g != c)
			err('n');
		i++;
	}
}

void	v_spatii(char *t)
{
	int	i;

	i = 0;
	if (t[0] == ' ')
		err('s');
	while (t[i])
	{
		if (t[i] == '\n')
			if (t[i + 1] == ' ' || t[i + 1] == '\t' || t[i + 1] == '\n')
				err('s');
		i++;
	}
}

void	verif(char *t)
{
	v_spatii(t);
	v_col(t);
}
