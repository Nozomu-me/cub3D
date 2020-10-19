/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:19 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 20:48:54 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

void		ft_sub_move_right_left(int key, t_cub *cub)
{
	if (key == 0)
	{
		if (cub->config.map[(int)(cub->player.pos.y -
		cub->player.plane.y * 0.2)][(int)cub->player.pos.x] != '1' &&
		cub->config.map[(int)(cub->player.pos.y -
		cub->player.plane.y * 0.2)][(int)cub->player.pos.x] != '2')
			cub->player.pos.y -= cub->player.plane.y * 0.2;
		if (cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x - cub->player.plane.x * 0.2)] != '1' &&
		cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x - cub->player.plane.x * 0.2)] != '2')
			cub->player.pos.x -= cub->player.plane.x * 0.2;
	}
}

void		ft_move_right_left(int key, t_cub *cub)
{
	ft_sub_move_right_left(key, cub);
	if (key == 2)
	{
		if (cub->config.map[(int)(cub->player.pos.y +
		cub->player.plane.y * 0.2)][(int)cub->player.pos.x] != '1' &&
		cub->config.map[(int)(cub->player.pos.y +
		cub->player.plane.y * 0.2)][(int)cub->player.pos.x] != '2')
			cub->player.pos.y += cub->player.plane.y * 0.2;
		if (cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x + cub->player.plane.x * 0.2)] != '1' &&
		cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x + cub->player.plane.x * 0.2)] != '2')
			cub->player.pos.x += cub->player.plane.x * 0.2;
	}
}
