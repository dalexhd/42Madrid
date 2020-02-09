/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:45:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/22 19:38:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_header(void)
{
	ft_printf("-------------------------------------------"
	"-----------------------------------------------------"
	"---------------------------------\n");
	ft_printf("---|\t"C_YELLOW"res"C_CLEAR"\t| --- |"C_YELLOW"type"C_CLEAR
	"| --- | "C_YELLOW"ll"C_CLEAR" |  "C_YELLOW"l"C_CLEAR" |  "C_YELLOW
	"L"C_CLEAR" | "C_YELLOW"hh"C_CLEAR" |  "C_YELLOW"h"C_CLEAR" |  "C_YELLOW
	"z"C_CLEAR" | --- |\t"C_YELLOW"str"C_CLEAR"\t| --- |\t"C_YELLOW
	"count"C_CLEAR"\t| --- |\t"C_YELLOW"width"C_CLEAR"\t| --- |\t"C_YELLOW
	"precision"C_CLEAR"|\n");
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
