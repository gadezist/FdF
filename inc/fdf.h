/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:32:39 by abytko            #+#    #+#             */
/*   Updated: 2018/04/21 19:21:09 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include "mlx.h"
# include "../lib/libft/libft.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>

# define SIZE_W 1920
# define SIZE_H 1500

typedef struct		s_data
{
	double			x;
	double			y;
	double			z;
	int				d;
	int				dx;
	int				dy;
	int				lx;
	int				ly;
	int				length_x;
	int				length_y;
	int				length_max;
	int				max_z;
	int				min_z;
	int				color;
	int				d_color;
	struct s_data	*next;
}					t_data;
typedef struct		s_image
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*str;
	int				per_pixel;
	int				endian;
	int				size_w;
	int				valid_x;
	t_data			*data;
}					t_image;
void				ft_list_pushback(t_data **list, double x, double y,
					double z);
t_data				*ft_new_list(double x, double y, double z);
void				ft_draw(t_image *image);
void				ft_draw_first(t_image *image);
void				ft_route_z(t_data *header, double corner);
void				ft_route_x(t_data *header, double corner);
void				ft_route_y(t_data *header, double corner);
int					keyput(int key, t_image *list);
void				ft_zoom_plus(t_data *header, int zoom);
void				ft_zoom_minus(t_data *header, int zoom);
void				ft_center_and_color(t_data *head);
void				ft_move(t_data *head, int key, int move);
int					ft_brezenhem(t_image *image);
void				ft_free_list(t_data *head);
int					mouseput(void *image);
void				ft_usage(t_image *image);
int					ft_error(void);
int					ft_exaption(void);

#endif
