/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:23:18 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/13 19:57:41 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_FILE_H
# define CONFIG_FILE_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct	s_colors
{
	int			r;
	int			g;
	int			b;
}				t_colors;

typedef struct	s_resol
{
	int			x;
	int			y;
}				t_resol;
typedef struct	s_boolean
{
	int			b;
	int			x;
	int			y;
	int			z;
}				t_boolean;
typedef struct	s_infos
{
	t_resol		r;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			colomns;
	int			lines;
	t_colors	c;
	t_colors	f;
	char		**map;
}				t_infos;

int				ft_isnumeric(char *str);
char			*ft_charjoin(char const *s1, char c);
int				ft_start_with(char *s1, char *s2);
void			ft_parsing_resol(char *line, t_infos *infos);
char			*ft_parsing_path(char *line, char *str, t_infos *infos);
t_colors		ft_parsing_colors(char *line, char *str, t_infos *infos);
void			ft_check_colors(char *str, t_infos *infos);
void			ft_store_map(t_infos *infos, char *str);
void			ft_sub_config_file(t_infos *infos, char *line);
t_infos			ft_config_file();
void			ft_print_error(char *str, t_infos *infos);
void			ft_free_tab(char **tab);
void			ft_free_struct(t_infos *infos);
void			ft_free_map(char **map);
int				ft_bigger_len(char *s1, char *s2);
int				ft_check_config(t_infos *infos);
int				ft_check_map_dim(char *chaine, t_infos *infos);
void			ft_s_store_map(char *str, char **map,
				int l, int c, t_infos *info);
void			ft_free(t_infos *infos);
int				ft_isvalid(char c);
int				ft_isplayer_pos(char c);
char			*ft_manage_config_file(char *line, int fd, t_infos *infos);
int				ft_valid(char c);
void			ft_struct_init(t_infos *infos);
void			ft_sub_manage_config_file(char *tmp, char *line, char **chaine);
void			ft_config_file_helper(char *str, char *l,
				t_infos *infos, int fd);
void			ft_parsing_map(char *str, t_infos *infos, int fd);
int				ft_check(t_infos *infos, int i, int j);
void			ft_sub_check_map_closed(t_infos *infos, int i, int j);
void			ft_check_map_closed(t_infos *infos);
void			ft_check_map_valid(t_infos *infos, t_boolean *b);
void			ft_sub_check_map_valid(t_infos *infos,
				t_boolean *b, int i, int j);
void			ft_check_map_iscomplete(t_infos *infos, t_boolean *b);
void			ft_store_map(t_infos *infos, char *str);
int				ft_ismap(char *str);
#endif
