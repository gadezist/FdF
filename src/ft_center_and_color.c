/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:37:43 by abytko            #+#    #+#             */
/*   Updated: 2018/05/02 18:22:18 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_center(t_data *head, int lx, int ly)
{
	int		max_z;
	int		min_z;
	t_data	*temp;

	temp = head;
	max_z = 0;
	min_z = 0;
	while (temp)
	{
		if (temp->z > 0 && temp->z > max_z)
			max_z = temp->z;
		else if (temp->z < 0 && temp->z < min_z)
			min_z = temp->z;
		temp->x = temp->x - lx / 2;
		temp->y = temp->y - ly / 2;
		temp = temp->next;
	}
	head->max_z = max_z;
	head->min_z = min_z;
	return ;
}

static void	ft_set_color(t_data *head)
{
	t_data	*temp;
	int		red;
	int		blue;
	int		green;
	int		stap;

	temp = head;
	stap = 255;
	if (head->max_z != 0 && head->max_z != 1)
		stap = 255 / (head->max_z / 2);
	red = 0x010000 * stap;
	green = 0x000100 * stap;
	blue = 0x000001 * stap;
	while (temp)
	{
		if (temp->z == 0 && temp->color == 0)
			temp->color = 0x00ff00;
		else if (temp->z > 0 && temp->z <= head->max_z / 2 && temp->color == 0)
			temp->color = red * temp->z + 0x00ff00;
		else if (temp->z > 0 && temp->z > head->max_z / 2 && temp->color == 0)
			temp->color = 0xffff00 - green * temp->z;
		else if (temp->color == 0)
			temp->color = blue * fabs(temp->z) + 0x00ff00;
		temp = temp->next;
	}
}

void		ft_center_and_color(t_data *head)
{
	t_data	*temp;
	int		lx;
	int		ly;
	int		tmp_x;

	lx = 0;
	ly = 0;
	if (!(temp = head))
		return ;
	while (temp)
	{
		tmp_x = lx;
		lx = 0;
		while (temp && (int)temp->y == ly + SIZE_H / 2)
		{
			temp->lx = lx;
			temp->ly = ly;
			lx++;
			temp = temp->next;
		}
		ly++;
	}
	head->lx = lx;
	ft_set_center(head, lx, ly);
	ft_set_color(head);
}
