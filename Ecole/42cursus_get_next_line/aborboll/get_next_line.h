/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:50:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/21 17:20:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>
# include <strings.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE	4096

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef int				t_bool;

int	get_next_line(int fd, char **line);

#endif
