/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_draw_sprite_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:55:43 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 20:49:48 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

void		ft_sort_sprite(t_cub *cub)
{
	int				i;

	i = 0;
	while (i < cub->sprite_nbr)
	{
		cub->sprite[i].dist = (pow(cub->player.pos.x - cub->sprite[i].posx, 2)
		+ pow(cub->player.pos.y - cub->sprite[i].posy, 2));
		i++;
	}
	ft_sort_integer_table(cub);
}

void		ft_sub_draw_s(t_cub *cub, t_sprit *s, int i)
{
	int				j;
	int				d;
	int				color;

	j = s->draw.start_y;
	while (j < s->draw.end_y)
	{
		d = j * 256 - cub->config.r.y * 128 + s->sprite.height * 128;
		s->tex.y = ((d * s->text.height) / s->sprite.height) / 256;
		color = cub->texture[4].data[cub->texture[4].width *
		s->tex.y + s->tex.x];
		if ((color & 0x00FFFFFF) != 0)
			cub->mlx.img.data[j * cub->config.r.x + i] = color;
		j++;
	}
}

void		ft_draw_s(t_cub *cub, double buf[cub->config.r.x], t_sprit *s)
{
	int				i;

	i = s->draw.start_x;
	while (i < s->draw.end_x)
	{
		s->tex.x = (int)(256 * (i - (-s->sprite.width / 2 +
		s->sprite.screen_x)) * s->text.width / s->sprite.width) / 256;
		if (s->trans.y > 0 && i > 0 && i < cub->config.r.x
		&& s->trans.y < buf[i])
			ft_sub_draw_s(cub, s, i);
		i++;
	}
}
