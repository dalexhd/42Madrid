/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:55:19 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/11 11:59:39 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "types.h"

/*
** Incluimos las librerias esenciales.
*/
# include <stdarg.h>
# include <stdbool.h>

/*
** Definimos la cantidad de flags necesarios:
*/
# define N_FLAGS 8

/*
** Usamos las siguientes longitudes:
** [t_ulong, t_ushsort, t_uint, t_ulong, t_ullong, size_t]
*/
# define N_LENS 8

typedef struct	s_info
{
	int			flags[N_FLAGS];
	int			width;
	int			length[N_LENS];
	int			precision;
	char		type;
	va_list		*args;
	char		**str;
	int			count;
	char		*res;
}				t_info;

enum			e_flags
{
	F_Neg,
	F_Plus,
	F_Space,
	F_Star,
	F_Zero,
	F_Hash,
	F_Trash,
	F_Argv0
};

enum			e_lengths
{
	L_short,
	L_char,
	L_uchar,
	L_long,
	L_ulong,
	L_longlong,
	L_size,
	L_longdouble,
};

int				ft_printf(char *format, ...);
int				ft_fprintf(int fd, char *format, ...);
int				ft_vfprintf(int fd, char *format, va_list *args);
int				ft_vprintf(char *format, va_list *args);
void			print(t_info *info);
void			check_and_print(t_info *info);
void			init_struct(t_info *info, char **str, va_list *args);
void			reinit(t_info *info);
void			reinit_lengths(t_info *info);

void			do_number(t_info *info, int neg);
void			do_string(t_info *info);
void			do_address(t_info *info);
void			do_char(t_info *info);
void			do_percentage(t_info *info);
void			do_hex(t_info *info);
void			do_octal(t_info *info);

void			debug(t_info *info);
void			print_header();

void			check_flags(t_info *info);
void			check_type(t_info *info);
void			check_width(t_info *info);
void			check_for_precision(t_info *info);
void			check_for_lengths(t_info *info);

int				apply_negative(t_info *info);

t_bool			is_type(char c);
t_bool			is_width(char c);
t_bool			is_flag(char c);
t_bool			is_precision(char c);
t_bool			is_length(char c);

#endif
