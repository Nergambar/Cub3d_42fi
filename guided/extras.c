/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:45:15 by negambar          #+#    #+#             */
/*   Updated: 2025/01/21 11:33:45 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	freemtx2(char **mtx)
{
	int	i;

	i = 0;
	if (mtx)
		freemtx(mtx);
}

int	ft_close(t_game *loop)
{
	if (loop->win)
		mlx_destroy_window(loop->mlx, loop->win);
	if (loop->img)
		mlx_destroy_image(loop->mlx, loop->img);
	if (loop->mlx)
	{
		mlx_destroy_display(loop->mlx);
		free(loop->mlx);
	}
	if (loop->map)
		freemtx2(loop->map);
	exit(0);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);
	}
	return (0);
}


int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

t_ray	*ray_lstnew(float x, float y, float angle, float fix_dist)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray) + 1); // MAH
	ray->angle = angle;
	ray->delta_x = x - (int)x;
	ray->delta_y = y - (int)y;
	ray->tile = which_wall(x, y);
	ray->fix_dist = fix_dist;
	return (ray);
}

float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}
