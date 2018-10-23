/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:44:36 by abytko            #+#    #+#             */
/*   Updated: 2018/05/02 13:04:25 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_list_pushback(t_data **list, double x, double y, double z)
{
	t_data	*push;

	if (list == NULL)
		return ;
	push = *list;
	if (push)
	{
		while (push->next)
			push = push->next;
		push->next = ft_new_list(x, y, z);
	}
	else
		*list = ft_new_list(x, y, z);
}
