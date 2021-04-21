/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:40:12 by aborboll          #+#    #+#             */
/*   Updated: 2021/03/20 17:08:18 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libasm.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	char str1[] = "hello";
	char str2[] = 			"hello";
	char *str3;

	printf("Length: %zu\n", ft_strlen(str1));
	printf("%s\n", str1);
	ft_strcpy(str1, str2);
	printf("%s\n", str2);
	printf("%c\n", ft_strcmp("Hola", "Hol"));
	str3 = ft_strdup("Holaa");
	printf("%s\n", str3);
	return (0);
}
