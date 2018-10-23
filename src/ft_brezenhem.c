/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezenhem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:12:28 by abytko            #+#    #+#             */
/*   Updated: 2018/05/02 17:08:20 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_put_color(t_data *put_pixel, int len, int d_color)
{
	int	red;
	int	green;
	int	blue;
	int stap;
	int	len_max;

	len_max = put_pixel->length_max;
	stap = 255;
	if (len_max / 2 > 0)
		stap = 255 / (len_max / 2);
	red = 0x010000 * stap;
	green = 0x000100 * stap;
	blue = 0x000001 * stap;
	if (len_max == 0)
		return ;
	if (d_color < 0 && len_max - len <= len_max / 2)
		put_pixel->color = put_pixel->color + red;
	else if (d_color < 0 && len_max - len > len_max / 2)
		put_pixel->color = put_pixel->color - green;
	if (d_color > 0 && len_max - len < len_max / 2)
		put_pixel->color = put_pixel->color + green;
	else if (d_color > 0 && len_max - len >= len_max / 2)
		put_pixel->color = put_pixel->color - red;
	if (put_pixel->color > 0xffff00)
		put_pixel->color = 0xffff00;
}

static void			ft_line_x(t_image *image, t_data *first)
{
	int		length;
	t_data	*put_pixel;

	put_pixel = image->data;
	put_pixel->x = first->x;
	put_pixel->y = first->y;
	put_pixel->d = -first->length_x;
	length = first->length_max + 1;
	put_pixel->length_max = first->length_max;
	put_pixel->color = first->color;
	while (length--)
	{
		ft_put_color(put_pixel, length, first->d_color);
		ft_draw(image);
		put_pixel->x += first->dx;
		put_pixel->d += 2 * first->length_y;
		if (put_pixel->d > 0)
		{
			put_pixel->d -= 2 * first->length_x;
			put_pixel->y += first->dy;
		}
	}
	return ;
}

static void			ft_line_y(t_image *image, t_data *first)
{
	int		length;
	t_data	*put_pixel;

	put_pixel = image->data;
	put_pixel->x = first->x;
	put_pixel->y = first->y;
	put_pixel->d = -first->length_y;
	put_pixel->color = first->color;
	length = first->length_max + 1;
	put_pixel->length_max = first->length_max;
	put_pixel->color = first->color;
	while (length--)
	{
		ft_put_color(put_pixel, length, first->d_color);
		ft_draw(image);
		put_pixel->y += first->dy;
		put_pixel->d += 2 * first->length_x;
		if (put_pixel->d > 0)
		{
			put_pixel->d -= 2 * first->length_y;
			put_pixel->x += first->dx;
		}
	}
	return ;
}

static void			ft_brezen_draw(t_image *image, t_data *first, t_data *secon)
{
	image->data->next = NULL;
	first->dx = (secon->x - first->x) >= 0 ? 1 : -1;
	first->dy = (secon->y - first->y) >= 0 ? 1 : -1;
	first->length_x = fabs(secon->x - first->x);
	first->length_y = fabs(secon->y - first->y);
	first->length_max = (first->length_x >= first->length_y) ?
						first->length_x : first->length_y;
	first->d_color = first->color - secon->color;
	if (first->length_y <= first->length_x)
		ft_line_x(image, first);
	else
		ft_line_y(image, first);
	return ;
}

int					ft_brezenhem(t_image *img)
{
	t_data	*list;
	t_data	*temp;
	t_data	*top;
	t_data	put_pixel;

	top = img->data;
	list = img->data;
	temp = list;
	img->data = &put_pixel;
	while (temp)
	{
		if (temp->next && temp->ly == temp->next->ly)
			ft_brezen_draw(img, temp, temp->next);
		if (temp->ly > 0)
		{
			ft_brezen_draw(img, temp, top);
			top = top->next;
		}
		temp = temp->next;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	ft_usage(img);
	img->data = list;
	return (0);
}
