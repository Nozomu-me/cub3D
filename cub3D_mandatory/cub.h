/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:26:09 by amouassi          #+#    #+#             */
/*   Updated: 2020/10/19 13:15:10 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define SIZE 2

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "config_file.h"
# include "mlx.h"
// # pragma pack(2)

int g_save;

typedef struct  s_file_bmp
{
    int         file_size;
    int         reserved;
    int         offset;
    int         header_size;
    int         width;
    int         height;
}               t_file_bmp;

typedef struct  s_bmp
{
    char        plane[SIZE];
    char        bpp[SIZE];
    int         compression;
    int         bit_size;
    int         perpexx;
    int         perpexy;
    int         num_color;
    int         imp_color;
}               t_bmp;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_dir
{
	double			x;
	double			y;
}					t_dir;

typedef struct		s_plane
{
	double			x;
	double			y;
}					t_plane;

typedef struct		s_player
{
	t_pos			pos;
	t_dir			dir;
	t_plane			plane;
}					t_player;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				hieght;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_img			img;
}					t_mlx;

typedef struct		s_sprite
{
	double			posx;
	double			posy;
	double			dist;
}					t_sprite;

typedef struct		s_cub
{
	t_infos			config;
	t_player		player;
	t_mlx			mlx;
	int				sprite_nbr;
	t_sprite		*sprite;
	t_img			sprite_texture[3];
	t_img			texture[6];
	int				floor;
	int				ciel;
}					t_cub;

typedef struct		s_ray
{
	float			x0;
	float			y0;
	float			x1;
	float			y1;
}					t_ray;

typedef struct		s_floor
{
	float			stepx;
	float			stepy;
	float			x;
	float			y;
}					t_floor;

typedef struct		s_ceil
{
	int				x;
	int				y;
}					t_ceil;

typedef struct		s_text
{
	int				width;
	int				height;
}					t_text;

typedef struct		s_tex
{
	int				x;
	int				y;
}					t_tex;

typedef struct		s_draw
{
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
}					t_draw;

typedef struct		s_sprt
{
	int				screen_x;
	int				height;
	int				width;
	double			x;
	double			y;
}					t_sprt;

typedef struct		s_trans
{
	double			x;
	double			y;
}					t_trans;

typedef struct		s_sprit
{
	t_text			text;
	t_draw			draw;
	t_sprt			sprite;
	t_tex			tex;
	t_trans			trans;
}					t_sprit;

typedef struct		s_p
{
	int				p;
	float			pos_z;
}					t_p;

typedef struct		s_raydir
{
	double			x;
	double			y;
}					t_raydir;

typedef struct		s_map
{
	int				x;
	int				y;
}					t_map;

typedef struct		s_side
{
	double			dist_x;
	double			dist_y;
}					t_side;

typedef struct		s_delta
{
	double			dist_x;
	double			dist_y;
}					t_delta;

typedef struct		s_step
{
	int				x;
	int				y;
}					t_step;

typedef struct		s_ddraw
{
	int				start;
	int				end;
}					t_ddraw;

typedef struct		s_cast
{
	t_raydir		raydir;
	t_map			map;
	t_side			side;
	t_delta			delta;
	t_step			step;
	t_ddraw			draw;
	t_tex			tex;
	t_text			text;
	double			tex_pos;
	double			s_step;
	double			cam;
	int				line_h;
	double			perp_dist;
}					t_cast;

void				ft_get_player_data(t_infos infos, t_player *player);
t_player			ft_init_player(t_infos infos);
int					ft_count_sprites(t_infos infos);
t_sprite			*ft_get_sprites_data(t_infos infos);
void				ft_sort_integer_table(t_cub *cub);
int					deel_key(int key, void *param);
int					ft_close(void *param);
void				ft_move_up_down(int key, t_cub *cub);
void				ft_move_right_left(int key, t_cub *cub);
void				ft_rotate(int key, t_cub *cub);
void				ft_load_textures(t_cub *cub);
void				ft_raycasting(t_cub *cub);
void				ft_draw_floor_ceil(t_cub *cub);
void				ft_help_floor_ceil(int y, t_cub *cub,
					t_floor *floor, t_ceil *ceil);
void				ft_sort_sprite(t_cub *cub);
void				ft_sub_draw_s(t_cub *cub, t_sprit *s, int i);
void				ft_draw_s(t_cub *cub,
					double buf[cub->config.r.x], t_sprit *s);
void				ft_help_cast_sprite(t_cub *cub, t_sprit *s);
void				ft_sub_cast_sprite(t_sprit *s, t_cub *cub, int i);
void				ft_cast_sprite(t_cub *cub, double buf[cub->config.r.x]);
void				ft_draw_walls(t_cast *cast, t_cub *cub, int side, int x);
void				ft_sub_draw_walls(t_cast *cast, t_cub *cub, int x);
void				ft_check_raydir(t_cast *cast, t_cub *cub);
void				ft_check_hit(t_cast *cast, t_cub *cub, int *side);
double				ft_check_side(t_cast *cast, t_cub *cub, int *side);
void				get_colors(t_cub *cub);
void				save_bmp(t_cub *cub);
void				ft_help_main(char **argv);
#endif
