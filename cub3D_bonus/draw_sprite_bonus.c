/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:28:19 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 20:48:02 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

void		ft_help_cast_sprite(t_cub *cub, t_sprit *s)
{
	if (s->draw.start_y < 0)
		s->draw.start_y = 0;
	s->draw.end_y = s->sprite.height / 2 + cub->config.r.y / 2;
	if (s->draw.end_y >= cub->config.r.y)
		s->draw.end_y = cub->config.r.y - 1;
	s->sprite.width = abs((int)(cub->config.r.y / s->trans.y));
	s->draw.start_x = -s->sprite.width / 2 + s->sprite.screen_x;
	if (s->draw.start_x < 0)
		s->draw.start_x = 0;
	s->draw.end_x = s->sprite.width / 2 + s->sprite.screen_x;
	if (s->draw.end_x >= cub->config.r.x)
		s->draw.end_x = cub->config.r.x - 1;
}

void		ft_sub_cast_sprite(t_sprit *s, t_cub *cub, int i)
{
	double			inv_det;

	s->sprite.x = cub->sprite[i].posx - cub->player.pos.x;
	s->sprite.y = cub->sprite[i].posy - cub->player.pos.y;
	inv_det = 1.0 / (cub->player.plane.x * cub->player.dir.y -
	cub->player.dir.x * cub->player.plane.y);
	s->trans.x = inv_det * (cub->player.dir.y * s->sprite.x -
	cub->player.dir.x * s->sprite.y);
	s->trans.y = inv_det * (-cub->player.plane.y * s->sprite.x +
	cub->player.plane.x * s->sprite.y);
	s->sprite.screen_x = (int)((cub->config.r.x / 2) *
	(1 + s->trans.x / s->trans.y));
	s->sprite.height = abs((int)(cub->config.r.y / s->trans.y));
	s->draw.start_y = -s->sprite.height / 2 + cub->config.r.y / 2;
}

void		ft_cast_sprite(t_cub *cub, double buf[cub->config.r.x])
{
	t_sprit		s;
	int			i;

	s.text.width = cub->texture[4].width;
	s.text.height = cub->texture[4].hieght;
	ft_sort_sprite(cub);
	i = 0;
	while (i < cub->sprite_nbr)
	{
		ft_sub_cast_sprite(&s, cub, i);
		ft_help_cast_sprite(cub, &s);
		ft_draw_s(cub, buf, &s);
		i++;
	}
}
