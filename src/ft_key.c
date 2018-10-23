/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:49:34 by abytko            #+#    #+#             */
/*   Updated: 2018/05/04 14:13:16 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyput(int key, t_image *img)
{
	if (img)
	{
		if (key == 53)
			exit(EXIT_SUCCESS);
		else if (key == 2)
			ft_route_z(img->data, 0.1);
		else if (key == 0)
			ft_route_z(img->data, -0.1);
		else if (key == 1)
			ft_route_x(img->data, 0.1);
		else if (key == 13)
			ft_route_x(img->data, -0.1);
		else if (key == 12)
			ft_route_y(img->data, -0.1);
		else if (key == 14)
			ft_route_y(img->data, 0.1);
		else if (key == 69)
			ft_zoom_plus(img->data, 2);
		else if (key == 78)
			ft_zoom_minus(img->data, 2);
		else if (key == 123 || key == 124 || key == 125 || key == 126)
			ft_move(img->data, key, 10);
	}
	img->img_ptr = mlx_new_image(img->mlx_ptr, SIZE_W, SIZE_H);
	return (ft_brezenhem(img));
}
