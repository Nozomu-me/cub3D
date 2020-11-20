/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:46:24 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/06 11:27:20 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "config_file.h"

void		ft_sub_player_data(t_infos infos, t_player *player, int i, int j)
{
	if (infos.map[i][j] == 'N')
	{
		player->pos.x = j + 0.5;
		player->pos.y = i + 0.5;
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (infos.map[i][j] == 'W')
	{
		player->pos.x = j + 0.5;
		player->pos.y = i + 0.5;
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
}

void		ft_help_player_data(t_infos infos, t_player *player, int i, int j)
{
	if (infos.map[i][j] == 'S')
	{
		player->pos.x = j + 0.5;
		player->pos.y = i + 0.5;
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (infos.map[i][j] == 'E')
	{
		player->pos.x = j + 0.5;
		player->pos.y = i + 0.5;
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}

void		ft_get_player_data(t_infos infos, t_player *player)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos.lines)
	{
		j = 0;
		while (j < infos.colomns)
		{
			if (infos.map[i][j] == 'N' || infos.map[i][j] == 'W')
				ft_sub_player_data(infos, player, i, j);
			if (infos.map[i][j] == 'S' || infos.map[i][j] == 'E')
				ft_help_player_data(infos, player, i, j);
			j++;
		}
		i++;
	}
}

t_player	ft_init_player(t_infos infos)
{
	t_player		player;

	ft_get_player_data(infos, &player);
	return (player);
}
