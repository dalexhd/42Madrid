/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:45:27 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 22:41:25 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GENERIC_H
# define _GENERIC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 40960

typedef struct	s_elem
{
	int			size;
	int			size_y;
	char		free;
	char		obs;
	char		square;
}				t_elem;
void			ft_putnbr(int nbr);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_strlen(char *str);
int				**ft_init(char *file, t_elem *elem, int	c, int ret);
int				ft_skip(char *str);
t_elem			*ft_init_elem(char *full_buff, t_elem *elem);
char			*ft_strmemcat(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
int				**ft_solve(int **map, t_elem *elem, int *max);
int				ft_set_number(int **map, int x, int y, int *max);
char			**ft_set(int **map, t_elem *elem, int *max, int set);
char			**ft_sq(char **result, int pass[1], int num, t_elem *elem);
void			ft_print(char **map, int size, int y);
void			ft_putstrb(char *str, int len);
void			ft_info(char *str);
void			ft_warning(char *str);
void			ft_error(char *str);
void			ft_error_no_exit(char *str);
int				ft_checkerror(int argc);
void			ft_extract_error(char *str, char *msg);
int				c_m(int **map, t_elem *elem);
int				compare(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
int				ft_atoi(char *str);
int				ft_isprint(int c);
int				ft_skip(char *str);
int				is_open(char path[]);

#endif
