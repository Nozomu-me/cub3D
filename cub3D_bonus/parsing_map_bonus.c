/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:52:00 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/14 14:25:33 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void		ft_sub_count_colomns_lines(t_infos *infos, int fd)
{
	int			i;
	char		*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_ismap(line) == 1)
			ft_print_error("Error\n", infos);
		if (line[0] == ' ' || line[0] == '0' || line[0] == '1')
		{
			i = 0;
			while (line[i] != '\0')
				i++;
			if (infos->colomns < i)
				infos->colomns = i;
			infos->lines++;
			free(line);
			break ;
		}
		free(line);
	}
}

void		ft_count_colomns_lines(t_infos *infos, int fd)
{
	char		*line;
	int			i;

	line = NULL;
	ft_sub_count_colomns_lines(infos, fd);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != ' ' && line[0] != '0' && line[0] != '1')
			ft_print_error("Error\n", infos);
		if (ft_strncmp(line, "", ft_strlen(line)) == 0)
			ft_print_error("Error\nmap invalid", infos);
		i = 0;
		while (line[i] != '\0')
			i++;
		if (infos->colomns < i)
			infos->colomns = i;
		infos->lines++;
		free(line);
	}
	if (infos->lines == 0 && infos->lines == 0)
	{
		ft_print_error("Error\nmap not found", infos);
		ft_free_tab(infos->map);
	}
}

void		ft_allocate_map(t_infos *infos)
{
	int		i;
	int		j;

	infos->map = malloc((infos->lines + 1) * sizeof(char*));
	i = 0;
	while (i < infos->lines)
	{
		infos->map[i] = malloc(infos->colomns * sizeof(char));
		i++;
	}
	i = 0;
	while (i < infos->lines)
	{
		j = 0;
		while (j < infos->colomns)
		{
			infos->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void		ft_store_map(t_infos *infos, char *str)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(str, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_isdigit(line[0]) || line[0] == ' ')
		{
			j = 0;
			while (line[j] != '\0')
			{
				infos->map[i][j] = line[j];
				j++;
			}
			i++;
		}
		free(line);
	}
}

void		ft_parsing_map(char *str, t_infos *infos, int fd)
{
	t_boolean		b;

	b.x = 0;
	b.y = 0;
	b.z = 0;
	b.b = 0;
	infos->colomns = 0;
	infos->lines = 0;
	ft_count_colomns_lines(infos, fd);
	ft_allocate_map(infos);
	close(fd);
	ft_store_map(infos, str);
	ft_check_map_iscomplete(infos, &b);
	ft_check_map_valid(infos, &b);
	ft_check_map_closed(infos);
}
