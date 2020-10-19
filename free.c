/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:09:10 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 16:25:30 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "cub.h"

void		ft_free_struct(t_infos *infos)
{
	if (infos->no != NULL)
		free(infos->no);
	if (infos->so != NULL)
		free(infos->so);
	if (infos->we != NULL)
		free(infos->we);
	if (infos->ea != NULL)
		free(infos->ea);
	if (infos->s != NULL)
		free(infos->s);
}

void		ft_free(t_infos *infos)
{
	if (infos->no != NULL)
		free(infos->no);
	if (infos->so != NULL)
		free(infos->so);
	if (infos->we != NULL)
		free(infos->we);
	if (infos->ea != NULL)
		free(infos->ea);
	if (infos->s != NULL)
		free(infos->s);
	ft_free_tab(infos->map);
}

void		ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
