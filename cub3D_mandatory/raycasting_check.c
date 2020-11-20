/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:35:45 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/10 17:09:23 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "cub.h"
#include "mlx.h"

void	ft_check_raydir(t_cast *cast, t_cub *cub)
{
	if (cast->raydir.x < 0)
	{
		cast->step.x = -1;
		cast->side.dist_x = (cub->player.pos.x -
		cast->map.x) * cast->delta.dist_x;
	}
	else
	{
		cast->step.x = 1;
		cast->side.dist_x = (cast->map.x + 1.0 - cub->player.pos.x) *
		cast->delta.dist_x;
	}
	if (cast->raydir.y < 0)
	{
		cast->step.y = -1;
		cast->side.dist_y = (cub->player.pos.y - cast->map.y) *
		cast->delta.dist_y;
	}
	else
	{
		cast->step.y = 1;
		cast->side.dist_y = (cast->map.y + 1.0 - cub->player.pos.y) *
		cast->delta.dist_y;
	}
}

void	ft_check_hit(t_cast *cast, t_cub *cub, int *side)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (cast->side.dist_x < cast->side.dist_y)
		{
			cast->side.dist_x += cast->delta.dist_x;
			cast->map.x += cast->step.x;
			*side = 0;
		}
		else
		{
			cast->side.dist_y += cast->delta.dist_y;
			cast->map.y += cast->step.y;
			*side = 1;
		}
		if (cub->config.map[cast->map.y][cast->map.x] == '1')
			hit = 1;
	}
}

void	ft_sub_check_side(t_cast *cast, t_cub *cub, int *side, double *p_d)
{
	if (*side == 0)
		*p_d = (cast->map.x - cub->player.pos.x
		+ (1 - cast->step.x) / 2) / cast->raydir.x;
	else
		*p_d = (cast->map.y - cub->player.pos.y
		+ (1 - cast->step.y) / 2) / cast->raydir.y;
}

double	ft_check_side(t_cast *cast, t_cub *cub, int *side)
{
	double	wall_x;
	double	perp_dist;

	ft_sub_check_side(cast, cub, side, &perp_dist);
	cast->line_h = (int)(cub->config.r.y / perp_dist);
	cast->draw.start = -cast->line_h / 2 + cub->config.r.y / 2;
	if (cast->draw.start < 0)
		cast->draw.start = 0;
	cast->draw.end = cast->line_h / 2 + cub->config.r.y / 2;
	if (cast->draw.end >= cub->config.r.y)
		cast->draw.end = cub->config.r.y - 1;
	if (*side == 0)
		wall_x = cub->player.pos.y + perp_dist * cast->raydir.y;
	else
		wall_x = cub->player.pos.x + perp_dist * cast->raydir.x;
	wall_x -= floor((wall_x));
	cast->tex.x = (int)(wall_x * (double)(cast->text.width));
	if (*side == 0 && cast->raydir.x > 0)
		cast->tex.x = cast->text.width - cast->tex.x - 1;
	if (*side == 1 && cast->raydir.y < 0)
		cast->tex.x = cast->text.width - cast->tex.x - 1;
	return (perp_dist);
}
