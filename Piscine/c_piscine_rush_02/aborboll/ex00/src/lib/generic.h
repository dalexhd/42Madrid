/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:45:27 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:33:21 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GENERIC_H
# define _GENERIC_H

typedef struct	s_nbrtree
{
	char				*nbr;
	char				*nbrstr;
	struct s_nbrtree	*left;
	struct s_nbrtree	*right;
}				t_nbrtree;
void			try_zero(char *arg, t_nbrtree *my_tree);
void			ft_checkerror(int argc);
void			convert_to_word(char *arg, char *dicct, int j, int k);
int				ft_atoi(char *str);
int				calc_range(char *str, char *charset);
void			ft_clean_newline(char *str);
int				compare(char *dest, char *src);
int				count_words(char *str);
char			*extract_ln(char *src);
char			*malloc_word(char *str);
char			**ft_split_line(char *str);
char			*extract_words(char *src);
int				ft_str_is_alpha(char *str);
int				ft_isnbr(char *str);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				order_size(char **arr);
void			ft_putchar(char a);
t_nbrtree		*do_decens(t_nbrtree *ptr, int *i, int j, char **argv);
t_nbrtree		*do_decens2(char **argv, int *i, int j, t_nbrtree *my_tree);
t_nbrtree		*move_right_on_tree(t_nbrtree *binary, int n);
t_nbrtree		*move_left_on_tree(t_nbrtree *binary, int n);
void			ft_putstr(char *str);
void			ft_putstr_with_space(char *str);
void			order_max(int maxorder_size, char **a);
void			order_toorder(int toorder_size, char **toorder);
char			**sort_lines(char **toorder, char **maxorder);
char			**separate_order(char **table);
char			**ft_split(char *str, char *charset, int i, int j);
char			*ft_strcat(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
int				ft_strlen(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strstr_tunned(char *str, char *to_find);
char			*ft_strstr(char *str, char *to_find);
char			*reserve_memorynbr(char *next);
char			*reserve_memorynbrstr(char *next, char *nbrstr);
char			*set_nbr(char *nbr, t_nbrtree binary);
char			*set_nbrstr(char *nbrstr, t_nbrtree binary);
void			do_one_digit(t_nbrtree *my_tree, char **argv, int j, int i);
void			ft_swap(char *a, char *b);
void			ft_rev_int_tab(char *tab, int size);
char			**initargv(char *arg, int digits, int *j, int k);
void			revert_argv(char **argv, char *arg);
int				calc_i(int digits);
int				calc_next_digits(int digits);
t_nbrtree		*structure_tree(t_nbrtree *my_tree, int i);
void			print_number(char *arg, t_nbrtree *my_tree, int i, int k);
int				is_open(char path[]);
char			*get_dir(char *lang);
char			*load_dictionary(char *lang);
void			ft_error(char *str);
void			ft_error_no_exit(char *str);
void			ft_extract_error(char *str, char line);
void			ft_info(char *str);
void			ft_warning(char *str);
void			dto(int j, int *i, char **argv, t_nbrtree *my_tree);
int				calc_k(int k, char **argv, int j);
int				calc_next_digits(int digits);
void			dt(int j, int i, char **argv, t_nbrtree *my_tree);
#endif
