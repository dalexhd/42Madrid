/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 07:32:52 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 14:53:51 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/*
** Include our libraries.
*/
# include "../libft/includes/libft.h"
# include "../libft/includes/color.h"
# ifdef __linux__
#  include "../minilibx/linux/mlx.h"
# elif __APPLE__
#  include "../minilibx/opengl/mlx.h"
# endif

/*
** We assign the corresponding SO keyboard layout.
*/
# ifdef __linux__
#  include "keyboard/linux.h"
# elif __APPLE__
#  include "keyboard/darwin.h"
# endif

/*
** Include necessary libraries.
*/
# include <stdarg.h>
# include <mlx.h>
# include <stdio.h>
# include <time.h>
# include <signal.h>

/*
** Include our game global settings.
*/
# include "settings_bonus.h"

/*
** Include internal values of the cub3d.
*/
# include "internal_bonus.h"

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_texture
{
	char			*path;
	int				*ptr;
	void			*texture;
	char			*ext;
	int				start;
	int				end;
	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;
}					t_texture;

typedef struct		s_textures
{
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_texture		sprite;
	t_texture		floor;
	t_texture		ceiling;
}					t_textures;

typedef struct		s_move
{
	t_bool			forward;
	t_bool			backward;
	t_bool			right;
	t_bool			left;
}					t_move;

typedef struct		s_rotate
{
	t_bool			right;
	t_bool			left;
}					t_rotate;

typedef struct		s_player
{
	double			x;
	double			y;
	double			deg;
	double			speed;
	double			rotate_speed;
	t_move			moving;
	t_rotate		rotating;
	t_bool			shifting;
}					t_player;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_direction
{
	double			x;
	double			y;
}					t_direction;

typedef struct		s_vdirection
{
	double			x0;
	double			y0;
	double			x1;
	double			y1;
}					t_vdirection;

typedef struct		s_ivector
{
	int				x;
	int				y;
}					t_ivector;

typedef struct		s_ray
{
	t_direction		dir;
	t_direction		side;
	t_direction		delta;
	t_ivector		step;
	t_ivector		map;
	t_bool			is_north;
	t_texture		texture;
	int				start;
	int				end;
	int				height;
	double			shade;
	double			dist;
	int				wall_direction;
	int				texture_x;
	double			texture_step;
	double			texture_pos;
}					t_ray;

typedef struct		s_valid
{
	t_bool			screen;
	t_bool			textures;
	t_bool			map;
	t_bool			file;
}					t_valid;

typedef struct		s_tmp
{
	t_bool			width;
	t_bool			height;
	t_bool			safe_line;
	t_bool			y;
	t_bool			nullbef;
}					t_tmp;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			d;
	double			inv_det;
	t_ivector		texture;
	t_direction		transform;
	t_ivector		start;
	t_ivector		end;
	int				screen_x;
	int				v_move_screen;
	int				height;
	int				width;
	int				color;
}					t_sprite;

typedef struct		s_sprites
{
	size_t			count;
	t_sprite		*data;
}					t_sprites;

typedef struct		s_fps
{
	double			time;
	double			old_time;
	double			count;
	t_bool			showing;
}					t_fps;

typedef struct		s_game
{
	void			*mlx;
	void			*tmp_mlx;
	char			*tmp_map;
	void			*win;
	int				width;
	int				height;
	int				x;
	char			**map;
	char			**verify_map;
	double			*zbuffer;
	int				minimap;
	char			spawn;
	t_sprites		sprites;
	t_bool			bmp;
	t_img			img;
	t_ray			*rays;
	t_player		player;
	t_direction		dir;
	t_textures		textures;
	t_direction		plane;
	t_valid			valid;
	t_fps			fps;
	t_tmp			tmp;
}					t_game;

t_game				*load_game(int argc, char **argv);
void				parse_game(t_game *game, char *file);
/*
** Init functions.
*/
void				init_game(int argc, char **argv);
/*
** Colors functions.
*/
int					rgb_to_hex(int r, int g, int b);
int					convert_color(t_color color);
int					ft_color(int color, double dist);
int					ft_shade(int color, double dist);
/*
** Raycasting functions.
*/
t_ray				cast_ray(t_game *game, int x);
t_ray				cast_texture(t_game *game, t_ray ray);
t_ray				setup_ray(t_game *game, int x);
t_texture			ray_texture(t_game *game, t_ray ray);
int					ray_direction(t_ray ray);
void				raycasting(t_game *game);
t_bool				is_side(t_ray ray);
/*
** Window functions.
*/
void				init_window(t_game *game);
int					close_window(t_game *game);
/*
** Controls functions.
*/
void				load_controls(t_game *game);
void				ft_rotate(t_game *game);
void				ft_move(t_game *game);
void				ft_shift(t_game *game);
/*
** Movement functions.
*/
void				move_forward(t_game *game);
void				move_backward(t_game *game);
void				move_right(t_game *game);
void				move_left(t_game *game);
/*
** Player functions.
*/
void				set_player_position(t_game *game, size_t x, size_t y);
t_bool				is_moving(t_game *game);
t_bool				is_rotating(t_game *game);
t_bool				is_shifting(t_game *game);
/*
** Game internal functions.
*/
int					main_loop(t_game *game);
void				set_pixel(t_game *game, size_t pixel, int color);
void				draw_textured_line(t_game *game, size_t start,
	size_t end, t_ray ray);
int					take_screenshot(t_game *game);
void				fps_counter(t_game *game);
/*
** Validate functions.
*/
t_bool				valid_cubfile(char *file);
t_bool				validate_color(t_game *game, char *color, char *line);
t_bool				has_screen(t_game *game);
t_bool				has_textures(t_game *game);
t_bool				has_map(t_game *game, t_bool check);
t_bool				validate_map(t_game *game);
t_bool				validate_map_line(t_game *game, char *line, size_t num);
t_bool				validate_screen(t_game *game, char *res, char *height,
	char *width);
void				invalid_screen(t_game *game, char **size);
t_bool				valid_cub(t_game *game);
t_bool				validate_texture(t_game *game, char *path,
	char *name, char *de);
t_bool				valid_cub_struct(t_game *game);
/*
** Parse functions.
*/
void				parse(t_game *game, char *file);
int					parse_file(t_game *game, char *file);
void				parse_floor(t_game *game, char *line);
void				parse_ceiling(t_game *game, char *line);
void				parse_map(t_game *game, char *line);
void				parse_textures(t_game *game, char *line);
void				fill_map(t_game *game);
t_texture			load_texture(void *mlx_ptr, char *path);
/*
** Sprites functions.
*/
void				set_sprites(t_game *game);
void				draw_sprites(t_game *game);
/*
** Clear the memory of the game
** @param  {t_game*} game : The game instance
*/
void				clear_memory(t_game *game);
/*
** Clear an especific texture
** @param  {t_texture} texture : The texture to clear instance
** @param  {void*} mlx_ptr     : The mlx pointer
** @param  {t_bool*} delpath   : Delete the path painter
*/
void				clear_texture(t_texture texture, void *mlx_ptr,
	t_bool delpath);
#endif
