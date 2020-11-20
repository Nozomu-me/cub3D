/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:00:40 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 20:49:42 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

void	ft_sub_rotat(t_cub *cub, double rot_s, double *old_d_x, double *old_p_x)
{
	*old_d_x = cub->player.dir.x;
	cub->player.dir.x = cub->player.dir.x * cos(-rot_s) -
	cub->player.dir.y * sin(-rot_s);
	cub->player.dir.y = *old_d_x * sin(-rot_s) +
	cub->player.dir.y * cos(-rot_s);
	*old_p_x = cub->player.plane.x;
	cub->player.plane.x = cub->player.plane.x * cos(-rot_s) -
	cub->player.plane.y * sin(-rot_s);
	cub->player.plane.y = *old_p_x * sin(-rot_s) +
	cub->player.plane.y * cos(-rot_s);
}

void	ft_rotate(int key, t_cub *cub)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = 0.2;
	if (key == 123)
		ft_sub_rotat(cub, rot_speed, &old_dir_x, &old_plane_x);
	if (key == 124)
	{
		old_dir_x = cub->player.dir.x;
		cub->player.dir.x = cub->player.dir.x * cos(rot_speed) -
		cub->player.dir.y * sin(rot_speed);
		cub->player.dir.y = old_dir_x * sin(rot_speed) +
		cub->player.dir.y * cos(rot_speed);
		old_plane_x = cub->player.plane.x;
		cub->player.plane.x = cub->player.plane.x * cos(rot_speed) -
		cub->player.plane.y * sin(rot_speed);
		cub->player.plane.y = old_plane_x * sin(rot_speed) +
		cub->player.plane.y * cos(rot_speed);
	}
}
