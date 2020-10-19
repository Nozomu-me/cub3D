/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:35:07 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/14 14:31:03 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_sub_check_map_closed(t_infos *infos, int i, int j)
{
	if (i == 0 && (infos->map[i][j] != '1' && infos->map[i][j] != ' '))
	{
		ft_print_error("Error\nmap invalid", infos);
		ft_free_tab(infos->map);
	}
	if ((i == infos->lines - 1) && (infos->map[i][j] != '1' &&
	infos->map[i][j] != ' '))
	{
		ft_print_error("Error\nmap invalid", infos);
		ft_free_tab(infos->map);
	}
	if (j == 0 && (infos->map[i][j] != '1' && infos->map[i][j] != ' '))
	{
		ft_print_error("Error\nmap invalid", infos);
		ft_free_tab(infos->map);
	}
	if ((j == infos->colomns - 1) && (infos->map[i][j] != '1' &&
	infos->map[i][j] != ' '))
	{
		ft_print_error("Error\nmap invalid", infos);
		ft_free_tab(infos->map);
	}
}

void		ft_check_map_closed(t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->lines)
	{
		j = 0;
		while (j < infos->colomns)
		{
			ft_sub_check_map_closed(infos, i, j);
			if (infos->map[i][j] == '0' ||
			ft_isplayer_pos(infos->map[i][j]) == 1 ||
			infos->map[i][j] == '2')
			{
				if (ft_check(infos, i, j) == 1)
				{
					ft_print_error("Error\nmap invalid", infos);
					ft_free_tab(infos->map);
				}
			}
			j++;
		}
		i++;
	}
}

void		ft_sub_check_map_valid(t_infos *infos, t_boolean *b, int i, int j)
{
	if (b->b == 1 && ft_isplayer_pos(infos->map[i][j]) == 1)
	{
		ft_print_error("Error\ndouble player position", infos);
		ft_free_tab(infos->map);
	}
	if (ft_isplayer_pos(infos->map[i][j]) == 1)
		b->b = 1;
}

void		ft_check_map_valid(t_infos *infos, t_boolean *b)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->lines)
	{
		j = 0;
		while (j < infos->colomns)
		{
			ft_sub_check_map_valid(infos, b, i, j);
			if ((infos->map[i][j] != '0' && infos->map[i][j] != '1'
			&& infos->map[i][j] != '2' &&
			infos->map[i][j] != 'N' && infos->map[i][j] != 'S' &&
			infos->map[i][j] != 'E' &&
			infos->map[i][j] != 'W' && infos->map[i][j] != ' '))
			{
				ft_print_error("Error\ninvalid caracter in map", infos);
				ft_free_tab(infos->map);
			}
			j++;
		}
		i++;
	}
}

void		ft_check_map_iscomplete(t_infos *infos, t_boolean *b)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->lines)
	{
		j = 0;
		while (j < infos->colomns)
		{
			if (infos->map[i][j] == '0')
				b->x = 1;
			if (infos->map[i][i] == '1')
				b->y = 1;
			if (ft_isplayer_pos(infos->map[i][j]) == 1)
				b->z = 1;
			j++;
		}
		i++;
	}
	if (b->x == 0 || b->y == 0 || b->z == 0)
	{
		ft_print_error("Error\nmap incomplete", infos);
		ft_free_tab(infos->map);
	}
}
