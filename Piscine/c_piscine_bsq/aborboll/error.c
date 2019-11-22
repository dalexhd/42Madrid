/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:45:50 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 11:58:17 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/generic.h"

void	ft_error(char *str)
{
	char error[256];

	ft_strcpy(error, "\033[1;91m");
	ft_strcat(error, "❌  \033[4;31m");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
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

void	ft_extract_error(char *str, char *msg)
{
	char info[256];
	char error[256];

	ft_strcpy(error, "\033[1;91m");
	ft_strcat(error, "📕  \033[4;31m");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
	ft_strcpy(error, "\033[0;35m");
	ft_strcat(info, "\n\tℹ️  ");
	ft_strcat(info, msg);
	ft_strcat(info, "\033[0m");
	ft_putstr(info);
}

void	ft_info(char *str)
{
	char error[256];

	ft_strcpy(error, "\033[0;35m");
	ft_strcat(error, "ℹ️  ");
	ft_strcat(error, str);
	ft_strcat(error, "\033[0m");
	ft_putstr(error);
}

void	ft_warning(char *str)
{
	char danger[256];

	ft_strcpy(danger, "\033[1;93m");
	ft_strcat(danger, "⚠️  ");
	ft_strcat(danger, str);
	ft_strcat(danger, "\033[0m");
	ft_putstr(danger);
}
