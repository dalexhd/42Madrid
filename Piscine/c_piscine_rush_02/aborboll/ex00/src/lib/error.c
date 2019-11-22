/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:09:06 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:11:33 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../lib/generic.h"

void	ft_error(char *str)
{
	char error[256];

	ft_strcpy(error, "\033[1;91m");
	ft_strcat(error, "❌  \033[4;31m");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
	exit(1);
}

void	ft_error_no_exit(char *str)
{
	char error[256];

	ft_strcpy(error, "\033[1;91m");
	ft_strcat(error, "❌  \033[4;31m");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
}

void	ft_extract_error(char *str, char line)
{
	char error[256];
	char info[256];

	ft_strcpy(error, "\033[1;91m");
	ft_strcat(error, "📕  \033[4;31m");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
	ft_strcpy(&line, "\033[0;35m");
	ft_strcat(info, "\tℹ️  Línea");
	ft_strcat(info, &line);
	ft_strcat(info, "\033[0m");
	ft_putstr(info);
	exit(1);
}

void	ft_info(char *str)
{
	char error[256];

	ft_strcpy(error, "\033[0;35m");
	ft_strcat(error, "\tℹ️  ");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
	exit(1);
}

void	ft_warning(char *str)
{
	char danger[256];

	ft_strcpy(danger, "\033[1;93m");
	ft_strcat(danger, "⚠️  ");
	ft_strcat(danger, str);
	ft_strcat(danger, "\033[0m");
	ft_putstr(danger);
	exit(1);
}
