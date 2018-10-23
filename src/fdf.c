/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:27:08 by abytko            #+#    #+#             */
/*   Updated: 2018/05/07 15:19:23 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int		ft_put_z(char *line, unsigned int *i)
{
	double	z;
	int		count;
	char	*z_str;

	count = 1;
	while ((line[*i + count] >= '0' && line[*i + count] <= '9')
				|| line[*i + count] == ',' || line[*i + count] == 'x'
				|| (line[*i + count] >= 'A' && line[*i + count] <= 'F')
				|| (line[*i + count] >= 'a' && line[*i + count] <= 'f'))
	{
		count++;
	}
	z_str = ft_strsub(line, *i, count);
	z = ft_atoi(z_str);
	free(z_str);
	*i += count;
	return (z);
}

static int		ft_create_list(t_image *image, char *line, double y)
{
	unsigned int	i;
	double			x;
	int				j;

	j = 0;
	i = 0;
	x = SIZE_W / 2;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			ft_list_pushback(&image->data, x, y, ft_put_z(line, &i));
			x++;
		}
		else
			i++;
	}
	if (image->valid_x && image->valid_x != (int)x)
		return (ft_error());
	else if (!image->valid_x)
		image->valid_x = x;
	return (1);
}

static t_image	*ft_image_open(t_image *image, t_data *head)
{
	image = (t_image *)malloc(sizeof(t_image));
	image->endian = 0;
	image->per_pixel = 0;
	image->size_w = 0;
	image->valid_x = 0;
	image->mlx_ptr = mlx_init();
	image->win_ptr = mlx_new_window(image->mlx_ptr, SIZE_W, SIZE_H, "fdf");
	image->img_ptr = mlx_new_image(image->mlx_ptr, SIZE_W, SIZE_H);
	image->data = head;
	return (image);
}

static int		ft_read_map(char *arg, t_image *image)
{
	double	y;
	int		fd;
	char	*line;

	y = SIZE_H / 2;
	line = NULL;
	if ((fd = open(arg, O_RDWR)) == -1)
		return (ft_exaption());
	if (errno == EISDIR)
		return (ft_exaption());
	while (get_next_line(fd, &line))
	{
		if (!ft_create_list(image, line, y++))
			return (0);
		free(line);
	}
	free(line);
	return (1);
}

int				main(int argc, char **argv)
{
	t_image		*image;
	t_data		*list;

	list = NULL;
	image = NULL;
	if (!(image = ft_image_open(image, list)))
		return (0);
	if (argc == 2)
	{
		if (ft_read_map(argv[1], image) == 0)
			return (0);
	}
	else
		return (0);
	if (!image->data)
		return (0);
	ft_center_and_color(image->data);
	ft_draw_first(image);
	mlx_hook(image->win_ptr, 2, 5, keyput, image);
	mlx_hook(image->win_ptr, 17, 1L << 17, mouseput, image);
	mlx_loop(image->mlx_ptr);
	return (0);
}
