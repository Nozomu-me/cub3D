/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:57:59 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 17:11:46 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "cub.h"
#include "mlx.h"

void		ft_sub_move_up_down(int key, t_cub *cub)
{
	if (key == 13)
	{
		if (cub->config.map[(int)(cub->player.pos.y +
		cub->player.dir.y * 0.2)][(int)cub->player.pos.x] != '1' &&
		cub->config.map[(int)(cub->player.pos.y +
		cub->player.dir.y * 0.2)][(int)cub->player.pos.x] != '2')
			cub->player.pos.y += cub->player.dir.y * 0.2;
		if (cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x + cub->player.dir.x * 0.2)] != '1' &&
		cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x + cub->player.dir.x * 0.2)] != '2')
			cub->player.pos.x += cub->player.dir.x * 0.2;
	}
}

void		ft_move_up_down(int key, t_cub *cub)
{
	ft_sub_move_up_down(key, cub);
	if (key == 1)
	{
		if (cub->config.map[(int)(cub->player.pos.y -
		cub->player.dir.y * 0.2)][(int)cub->player.pos.x] != '1' &&
		cub->config.map[(int)(cub->player.pos.y -
		cub->player.dir.y * 0.2)][(int)cub->player.pos.x] != '2')
			cub->player.pos.y -= cub->player.dir.y * 0.2;
		if (cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x - cub->player.dir.x * 0.2)] != '1' &&
		cub->config.map[(int)cub->player.pos.y][(int)
		(cub->player.pos.x - cub->player.dir.x * 0.2)] != '2')
			cub->player.pos.x -= cub->player.dir.x * 0.2;
	}
}
