/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:45:46 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/12 15:09:17 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void		ft_help_floor_ceil(int y, t_cub *cub, t_floor *floor, t_ceil *ceil)
{
	int		i;
	int		tx;
	int		ty;
	t_text	text;

	text.width = cub->texture[0].width;
	text.height = cub->texture[0].hieght;
	i = 0;
	while (i < cub->config.r.x)
	{
		ceil->x = (int)(floor->x);
		ceil->y = (int)(floor->y);
		tx = (int)(text.width * (floor->x - ceil->x)) & (text.width - 1);
		ty = (int)(text.height * (floor->y - ceil->y)) & (text.height - 1);
		floor->x += floor->stepx;
		floor->y += floor->stepy;
		cub->mlx.img.data[y * cub->config.r.x + i] =
		cub->texture[5].data[cub->texture[5].width * ty + tx];
		cub->mlx.img.data[(cub->config.r.y - y - 1) * cub->config.r.x + i] =
		cub->texture[6].data[cub->texture[6].width * ty + tx];
		i++;
	}
}

void		ft_draw_floor_ceil(t_cub *cub)
{
	int			y;
	t_p			p;
	t_ray		rayd;
	t_floor		floor;
	t_ceil		ceil;

	y = cub->config.r.y / 2 + 1;
	while (y < cub->config.r.y)
	{
		rayd.x0 = cub->player.dir.x - cub->player.plane.x;
		rayd.y0 = cub->player.dir.y - cub->player.plane.y;
		rayd.x1 = cub->player.dir.x + cub->player.plane.x;
		rayd.y1 = cub->player.dir.y + cub->player.plane.y;
		p.p = y - cub->config.r.y / 2;
		p.pos_z = 0.5 * cub->config.r.y;
		floor.stepx = (p.pos_z / p.p) * (rayd.x1 - rayd.x0) / cub->config.r.x;
		floor.stepy = (p.pos_z / p.p) * (rayd.y1 - rayd.y0) / cub->config.r.x;
		floor.x = cub->player.pos.x + (p.pos_z / p.p) * rayd.x0;
		floor.y = cub->player.pos.y + (p.pos_z / p.p) * rayd.y0;
		ft_help_floor_ceil(y, cub, &floor, &ceil);
		y++;
	}
}
