/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtopor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:46:37 by mtopor            #+#    #+#             */
/*   Updated: 2018/01/23 19:46:38 by mtopor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include "get_next_line.h"

# define WHITE 16777215
# define WIDTH	1000
# define HEIGHT	1000
# define WIDTHIMG 1000
# define HEIGHTIMG 1000
# define CTE 0.5
# define CTE2 4
# define CTE3 2
# define DIST 5
# define ANGLE 45

int		g_k;

typedef struct		s_ij
{
	int		i;
	int		j;
}					t_ij;

typedef	struct		s_mlx
{
	void	*win;
	void	*mlx;
	int		width;
	int		height;
	int		i;
	int		j;

}					t_mlx;

typedef struct		s_data
{

	int		size_line;
	int		endian;
	char	*data;
	int		bpp;
	void	*img;
}					t_data;

typedef struct		s_lc
{
	int		lin;
	int		col;
}					t_lc;

typedef struct		s_pct
{
	double		x;
	double		y;
}					t_pct;

typedef struct		s_3d
{
	double		x;
	double		y;
	double		z;
	float		new_x;
	float		new_y;
}					t_3d;

typedef struct		s_col
{
	int		r;
	int		g;
	int		b;
}					t_col;

typedef struct		s_config
{
	float		cols;
	float		spacing;
	float		rows;
	float		angle;
	float		unghi;
	float		move_x;
	float		move_y;
	t_3d		**tab;
	t_data		*img;
	float		hight;
}					t_config;

typedef struct		s_line
{
	t_3d		a;
	t_3d		b;
	int			dx;
	int			dy;
	int			err;
	int			e2;
	int			sx;
	int			sy;
}					t_line;

t_config			get_config(int lin, int col);
void				clean_version(t_3d **tab, t_config *conf);
void				print_point(t_3d p);
t_3d				getpoint_fromstr(char *s, t_lc *ij);
int					is_clean(char *s);
void				error(char *s);
t_3d				**get_data(char *s, t_lc *lc);
void				afis_3d(t_3d **tab, int l, int c);
float				get_step(int rows, int col);
void				init(t_mlx *c);
int					getnbr(char *s);
char				**ft_split_whitespaces(char *str, char c);
void				verif(char *t);
t_3d				**v_val(char *t, int *l, int *c);
char				*ft_readdata(char *fis);
int					ft_strlen(char *s);
void				err(char n);
void				afis(int **t, int li, int co);
void				ft_start(t_3d **tab, t_lc lc, t_config *conf);
void				ft_putstr(char *s);
void				set_pixel(int x, int y, t_data *img);
void				put_pixel(char *img, int sln, t_3d z, int col);
void				line(t_3d z, t_3d u, t_data *img);
void				draw(t_3d **c, t_config *conf);
void				afis(int **tab, int l, int c);
int					keys(int key, t_config *conf);
void				initij(t_ij *ij);
int					keys_doi(int key, t_config *conf);

#endif
