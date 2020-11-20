# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 19:19:58 by amouassi          #+#    #+#              #
#    Updated: 2020/03/13 13:29:34 by amouassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = libft
NAMELIBFT = libft.a
EXE = cub3D
GNL = get_next_line

SRCLIB =  ft_atoi.c \
		  ft_bzero.c \
	      ft_calloc.c \
	  	  ft_isalnum.c \
	 	  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c

SRCGNL = get_next_line.c \

SRC = config_file_utils.c \
	  config_file.c \
	  free.c \
	  get_player_data.c \
	  get_sprite_data.c \
	  map_parsing_utils.c \
	  parsing_path.c \
	  parsing_resol.c \
	  utils.c \
	  load_textures.c \
	  rotate.c \
	  move_left_right.c \
	  move_up_down.c \
	  key.c \
	  draw_floor_ceil.c \
	  draw_sprite.c \
	  sub_draw_sprite.c \
	  draw_walls.c \
	  raycasting_check.c \
	  raycasting.c \
	  parsing_map.c \
	  parsing_colors.c \
	  get_colors.c \
	  sub_parsing_map.c  \
	  save.c

SRCB = config_file_utils_bonus.c \
	   config_file_bonus.c \
	   free_bonus.c \
	   get_player_data_bonus.c \
	   get_sprite_data_bonus.c \
	   map_parsing_utils_bonus.c \
	   parsing_path_bonus.c \
	   parsing_resol_bonus.c \
	   utils_bonus.c \
	   load_textures_bonus.c \
	   rotate_bonus.c \
	   move_left_right_bonus.c \
	   move_up_down_bonus.c \
	   key_bonus.c \
	   draw_floor_ceil_bonus.c \
	   draw_sprite_bonus.c \
	   sub_draw_sprite_bonus.c \
	   draw_walls_bonus.c \
	   raycasting_check_bonus.c \
	   raycasting_bonus.c \
	   parsing_map_bonus.c \
	   save_bonus.c \
	   sub_parsing_map_bonus.c  
		  
CAST = raycast_main.c
CASTB = raycast_main_bonus.c
FRAME =  -lmlx -framework OpenGl -framework AppKit
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
OBJLIB = $(addprefix $(LIBFT)/,$(SRCLIB:.c=.o))
OBJGNL = $(addprefix $(GNL)/,$(SRCLIB:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) $(OBJGNL)
	$(AR) $(NAME) $(OBJ) $(OBJLIB) $(OBJGNL)
	$(CC) $(FLAG) $(FRAME) $(CAST) $(NAME) -o $(EXE)

bonus: $(OBJB) $(OBJLIB) $(OBJGNL)
	$(AR) $(NAME) $(OBJB) $(OBJLIB) $(OBJGNL)
	$(CC) $(FLAG) $(FRAME) $(CASTB) $(NAME) -o $(EXE)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJLIB)
	rm -f $(OBJB)
	rm -f $(OBJGNL)
	rm -f raycast_main.o
	rm -f raycast_main_bonus.o
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(NAMELIBFT)

re: fclean all