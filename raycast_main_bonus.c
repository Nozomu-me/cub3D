/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:06:41 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/13 13:47:00 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

void		ft_help_main(char **argv)
{
	if (ft_strncmp(argv[2], "--save", ft_bigger_len(argv[2], "--save")) == 0)
		g_save = 1;
	else
	{
		ft_putstr_fd("Error\nsave argument is not correct", 1);
		exit(EXIT_FAILURE);
	}
}

void		ft_check_file_extension(char **argv, int argc)
{
	int		i;
	char	**split;

	i = 0;
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nnumber of arguments is not correct", 1);
		exit(EXIT_FAILURE);
	}
	split = ft_split(argv[1], '.');
	while (split[i] != NULL)
		i++;
	if (ft_strncmp(split[i - 1], "cub",
	ft_bigger_len(split[i - 1], "cub")) != 0)
	{
		ft_putstr_fd("Error\nfile extension is invalid", 1);
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
		ft_help_main(argv);
}

int			main(int argc, char **argv)
{
	t_cub		cub;

	g_save = 0;
	ft_check_file_extension(argv, argc);
	cub.config = ft_config_file(argv[1]);
	cub.player = ft_init_player(cub.config);
	cub.sprite_nbr = ft_count_sprites(cub.config);
	cub.sprite = ft_get_sprites_data(cub.config);
	cub.mlx.mlx_ptr = mlx_init();
	if (g_save == 0)
		cub.mlx.win = mlx_new_window(cub.mlx.mlx_ptr,
		cub.config.r.x, cub.config.r.y, "cub3d");
	cub.mlx.img.img_ptr = mlx_new_image(cub.mlx.mlx_ptr, cub.config.r.x,
	cub.config.r.y);
	cub.mlx.img.data = (int *)mlx_get_data_addr(cub.mlx.img.img_ptr,
	&cub.mlx.img.bpp, &cub.mlx.img.size_l, &cub.mlx.img.endian);
	ft_raycasting(&cub);
	mlx_hook(cub.mlx.win, 2, 0, deel_key, &cub);
	mlx_hook(cub.mlx.win, 17, 0, ft_close, NULL);
	mlx_loop(cub.mlx.mlx_ptr);
	ft_free(&cub.config);
	free(cub.sprite);
	return (0);
}
