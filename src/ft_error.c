/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:22:24 by abytko            #+#    #+#             */
/*   Updated: 2018/05/03 13:53:49 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(void)
{
	ft_putstr("Found wrong line length. Exiting.\n");
	return (0);
}

int	ft_exaption(void)
{
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (0);
}
