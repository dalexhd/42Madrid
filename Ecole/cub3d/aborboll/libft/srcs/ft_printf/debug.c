/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:45:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 21:26:44 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print_header(void)
{
	ft_printf("-------------------------------------------"
	"-----------------------------------------------------"
	"---------------------------------\n");
	ft_printf("---|\t"C_YELLOW"res"C_X"\t| --- |"C_YELLOW"type"C_X
	"| --- | "C_YELLOW"ll"C_X" |  "C_YELLOW"l"C_X" |  "C_YELLOW
	"L"C_X" | "C_YELLOW"hh"C_X" |  "C_YELLOW"h"C_X" |  "C_YELLOW
	"z"C_X" | --- |\t"C_YELLOW"str"C_X"\t| --- |\t"C_YELLOW
	"count"C_X"\t| --- |\t"C_YELLOW"width"C_X"\t| --- |\t"C_YELLOW
	"precision"C_X"|\n");
}

void	debug(t_info *info)
{
	ft_printf("--------------------------------------------"
	"------------------------------------------------------"
	"-------------------------------\n");
	ft_printf("---|\t%s\t| --- | %c  | --- |  %i |  %i |  %i"
	" |  %i |  %i |  %i | --- |\t%s\t| --- |\t%i\t| --- |\t"
	"%i\t| --- |\t%i\t|\n",
				info->res,
				info->type ? info->type : ' ',
				info->length[L_longlong],
				info->length[L_long],
				info->length[L_longdouble],
				info->length[L_char],
				info->length[L_short],
				info->length[L_size],
				*info->str, info->count,
				info->width, info->precision);
}
