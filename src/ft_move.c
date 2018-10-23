/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:14:05 by abytko            #+#    #+#             */
/*   Updated: 2018/04/24 20:36:35 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_data *head, int key, int move)
{
	t_data *temp;

	temp = head;
	if (!head)
		return ;
	while (temp)
	{
		if (key == 123)
			temp->x = temp->x - move;
		else if (key == 124)
			temp->x = temp->x + move;
		else if (key == 125)
			temp->y = temp->y + move;
		else if (key == 126)
			temp->y = temp->y - move;
		temp = temp->next;
	}
	return ;
}
