/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:55:46 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/11 16:16:24 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

void		ft_sub_draw_walls(t_cast *cast, t_cub *cub, int x)
{
	if (cast->raydir.y > 0)
		cub->mlx.img.data[cast->draw.start * cub->config.r.x + x] =
		cub->texture[1].data[cub->texture[1].width * cast->tex.y
		+ cast->tex.x];
	else
		cub->mlx.img.data[cast->draw.start * cub->config.r.x + x] =
		cub->texture[0].data[cub->texture[0].width * cast->tex.y
		+ cast->tex.x];
}

void		ft_draw_walls(t_cast *cast, t_cub *cub, int side, int x)
{
	while (cast->draw.start < cast->draw.end)
	{
		cast->tex.y = (int)cast->tex_pos & (cast->text.height - 1);
		cast->tex_pos += cast->s_step;
		if (side == 0)
		{
			if (cast->raydir.x > 0)
				cub->mlx.img.data[cast->draw.start * cub->config.r.x + x] =
				cub->texture[3].data[cub->texture[3].width * cast->tex.y
				+ cast->tex.x];
			else
				cub->mlx.img.data[cast->draw.start * cub->config.r.x + x] =
				cub->texture[2].data[cub->texture[2].width * cast->tex.y
				+ cast->tex.x];
		}
		else if (side == 1)
			ft_sub_draw_walls(cast, cub, x);
		cast->draw.start++;
	}
}
