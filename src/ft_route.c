/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:39:12 by abytko            #+#    #+#             */
/*   Updated: 2018/04/26 14:01:38 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_route_x(t_data *header, double corner)
{
	double		y;
	double		z;
	t_data		*temp;

	temp = header;
	if (!header)
		return ;
	while (temp)
	{
		y = temp->y;
		z = temp->z;
		temp->y = ((y - SIZE_H / 2) * cos(corner) +
				z * sin(corner)) + SIZE_H / 2;
		temp->z = ((-y + SIZE_H / 2) * sin(corner) +
				z * cos(corner));
		temp = temp->next;
	}
	return ;
}

void	ft_route_y(t_data *header, double corner)
{
	double	x;
	double	z;
	t_data	*temp;

	temp = header;
	if (!header)
		return ;
	while (temp)
	{
		x = temp->x;
		z = temp->z;
		temp->x = ((x - SIZE_W / 2) * cos(corner) +
				z * sin(corner)) + SIZE_W / 2;
		temp->z = ((-x + SIZE_W / 2) * sin(corner) +
				z * cos(corner));
		temp = temp->next;
	}
	return ;
}

void	ft_route_z(t_data *header, double corner)
{
	double		x;
	double		y;
	t_data		*temp;

	temp = header;
	if (!header)
		return ;
	while (temp)
	{
		x = temp->x;
		y = temp->y;
		temp->x = ((x - SIZE_W / 2) * cos(corner) -
				(y - SIZE_H / 2) * sin(corner)) + SIZE_W / 2;
		temp->y = ((x - SIZE_W / 2) * sin(corner) +
				(y - SIZE_H / 2) * cos(corner)) + SIZE_H / 2;
		temp = temp->next;
	}
	return ;
}
