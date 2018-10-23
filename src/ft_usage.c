/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:40:59 by abytko            #+#    #+#             */
/*   Updated: 2018/05/02 17:10:48 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_usage(t_image *image)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = "Q & E = twist around the Y";
	str2 = "W & S = twist around the X";
	str3 = "A & D = twist around the Z";
	str4 = "+ = zoom plus";
	str5 = "- = zoom minus";
	mlx_string_put(image->mlx_ptr, image->win_ptr, 20, 20, 0xFFFFFF, str1);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 20, 40, 0xFFFFFF, str2);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 20, 60, 0xFFFFFF, str3);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 20, 80, 0xFFFFFF, str4);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 20, 100, 0xFFFFFF, str5);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 20, 120, 0xFFFFFF,
			"move the arrows");
}
