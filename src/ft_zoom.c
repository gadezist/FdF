/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:16:45 by abytko            #+#    #+#             */
/*   Updated: 2018/05/07 14:44:28 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_plus(t_data *header, int zoom)
{
	int		z_max;
	t_data	*temp;

	z_max = header->max_z;
	temp = header;
	if (!header)
		return ;
	while (temp)
	{
		temp->x = (temp->x - SIZE_W / 2) * zoom + SIZE_W / 2;
		temp->y = (temp->y - SIZE_H / 2) * zoom + SIZE_H / 2;
		if (zoom == SIZE_W / (header->lx * 2) && z_max >= 50)
			temp->z = temp->z * 5;
		else if (zoom == SIZE_W / (header->lx * 2) && z_max < 50)
			temp->z = temp->z * 10;
		else
			temp->z = temp->z * 2;
		temp = temp->next;
	}
	return ;
}

void	ft_zoom_minus(t_data *header, int zoom)
{
	t_data	*temp;

	temp = header;
	if (!header)
		return ;
	while (temp)
	{
		temp->x = (temp->x - SIZE_W / 2) / zoom + SIZE_W / 2;
		temp->y = (temp->y - SIZE_H / 2) / zoom + SIZE_H / 2;
		temp->z = temp->z / 2;
		temp = temp->next;
	}
	return ;
}
