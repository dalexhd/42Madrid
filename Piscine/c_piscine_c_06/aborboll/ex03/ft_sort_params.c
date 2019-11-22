/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:46:36 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/19 15:21:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	sort_argvs(int argc, char **argv)
{
	int		i;
	char	*temp;

	i = argc;
	while ((argc - 1) > 1)
	{
		i = argc;
		while (i > 1)
		{
			if (ft_strcmp(argv[i - 1], argv[argc - 1]) > 0)
			{
				temp = argv[i - 1];
				argv[i - 1] = argv[argc - 1];
				argv[argc - 1] = temp;
			}
			i--;
		}
		argc--;
	}
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	sort_argvs(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
