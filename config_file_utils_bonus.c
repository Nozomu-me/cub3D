/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:20:51 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/13 19:59:17 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"

void		ft_struct_init(t_infos *infos)
{
	infos->r.x = 0;
	infos->r.y = 0;
	infos->c = NULL;
	infos->f = NULL;
	infos->no = NULL;
	infos->so = NULL;
	infos->we = NULL;
	infos->ea = NULL;
	infos->s = NULL;
}

void		ft_print_error(char *str, t_infos *infos)
{
	ft_putstr_fd(str, 2);
	if (infos)
		ft_free_struct(infos);
	exit(EXIT_FAILURE);
}

int			ft_check_config(t_infos *infos)
{
	if (infos->r.x == 0 || infos->c == NULL || infos->f == NULL
	|| infos->no == NULL || infos->so == NULL ||
	infos->we == NULL || infos->ea == NULL || infos->s == NULL)
		return (1);
	return (0);
}
