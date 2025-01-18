/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:45:15 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 11:46:28 by negambar         ###   ########.fr       */
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
