/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:19:52 by abytko            #+#    #+#             */
/*   Updated: 2018/05/07 15:02:15 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_first(t_image *image)
{
	unsigned int	i;
	t_data			*list;

	i = 0;
	list = image->data;
	image->str = mlx_get_data_addr(image->img_ptr, &image->per_pixel,
								&image->size_w, &image->endian);
	image->per_pixel = image->per_pixel / 8;
	ft_zoom_plus(list, SIZE_W / (list->lx * 2));
	ft_route_x(list, -0.4);
	ft_route_y(list, -0.4);
	ft_route_z(list, 0.7);
	ft_brezenhem(image);
}

void		ft_draw(t_image *image)
{
	unsigned int	i;
	t_data			*list;

	i = 0;
	list = image->data;
	image->str = mlx_get_data_addr(image->img_ptr, &image->per_pixel,
								&image->size_w, &image->endian);
	image->per_pixel = image->per_pixel / 8;
	while (list)
	{
		i = ((int)list->x * image->per_pixel) + ((int)list->y * image->size_w);
		if (list->x >= 0 && list->x <= SIZE_W &&
				list->y >= 0 && list->y <= SIZE_H)
		{
			image->str[i] = list->color;
			image->str[++i] = list->color >> 8;
			image->str[++i] = list->color >> 16;
		}
		list = list->next;
	}
}
