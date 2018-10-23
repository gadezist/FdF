/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:38:22 by abytko            #+#    #+#             */
/*   Updated: 2018/05/02 11:24:08 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_new_list(double x, double y, double z)
{
	t_data *newlist;

	if (!(newlist = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	newlist->x = x;
	newlist->y = y;
	newlist->z = z;
	newlist->color = 0;
	newlist->next = NULL;
	return (newlist);
}
