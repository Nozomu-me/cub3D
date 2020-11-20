/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:56 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/13 13:20:41 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "config_file.h"

int				ft_count_sprites(t_infos infos)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (i < infos.lines)
	{
		j = 0;
		while (j < infos.colomns)
		{
			if (infos.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_sprite		*ft_get_sprites_data(t_infos infos)
{
	int			i;
	int			j;
	int			k;
	t_sprite	*sprite;

	i = 0;
	k = 0;
	sprite = malloc(sizeof(t_sprite) * ft_count_sprites(infos));
	while (i < infos.lines)
	{
		j = 0;
		while (j < infos.colomns)
		{
			if (infos.map[i][j] == '2')
			{
				sprite[k].posx = j + 0.5;
				sprite[k].posy = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	return (sprite);
}

void			ft_sort_integer_table(t_cub *cub)
{
	int			i;
	t_sprite	a;
	int			j;

	j = 0;
	while (j < cub->sprite_nbr)
	{
		i = 0;
		while (i < cub->sprite_nbr)
		{
			if (cub->sprite[i].dist < cub->sprite[i + 1].dist)
			{
				a = cub->sprite[i];
				cub->sprite[i] = cub->sprite[i + 1];
				cub->sprite[i + 1] = a;
			}
			i++;
		}
		j++;
	}
}
