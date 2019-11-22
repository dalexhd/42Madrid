/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwhat_calculator_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:50:49 by lacollar          #+#    #+#             */
/*   Updated: 2019/11/20 13:55:02 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_calculator.h"

static int			ft_nbr_of_digits(int n)
{
	int	i;

	i = 1;
	if (!n)
		return (i);
	while (n)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

static char			*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	new;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = -1;
	while (i > j++)
	{
		new = str[i];
		str[i] = str[j];
		str[j] = new;
		i--;
	}
	return (str);
}

static void			ft_check_non_null_nbr(int n, char *string)
{
	int		i;
	int		neg;
	long	nb;

	nb = (long)n;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	i = 0;
	if (nb)
	{
		while (nb <= -10 || nb >= 10)
		{
			string[i] = (nb % 10) + 48;
			nb /= 10;
			i++;
		}
		string[i] = (nb % 10) + 48;
	}
	if (neg == 1)
		string[i + 1] = '-';
}

char				*ft_itoa(int n)
{
	char	*string;
	char	*result;
	long	nb;

	nb = (long)n;
	if (!(string = (char*)malloc(sizeof(char) * (ft_nbr_of_digits(nb) +
						1))))
		return (NULL);
	if (!nb)
		string[0] = '0';
	if (nb)
		ft_check_non_null_nbr(nb, string);
	string[ft_nbr_of_digits(nb)] = '\0';
	result = ft_strrev(string);
	return (result);
}



void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	i = 0;
	if (!dst || !src || (n == 0))
		return (0);
	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (0);
}



static int				ft_count_charset(char const *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			x++;
		while (s[i] != c && s[i])
			i++;
	}
	return (x);
}

static int				ft_smallstr_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void				*ft_free_substr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = NULL;
		free(str[i]);
		i++;
	}
	str = NULL;
	free(str);
	return (NULL);
}

char					**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (!s || !(new = (char**)malloc(sizeof(char*) * (ft_count_charset(s, c) + 1))))
		return (NULL);
	while (++i < ft_count_charset(s, c))
	{
		k = 0;
		if (!(new[i] = (char*)malloc(sizeof(char) * (ft_smallstr_len(&s[j], c)
							+ 1))))
			return (ft_free_substr(new));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			new[i][k++] = s[j++];
		new[i][k] = '\0';
	}
	new[i] = 0;
	return (new);
}



void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	bzero(buffer, count * size);
	return (buffer);
}

char	*ft_strdup(const char *s1)
{
	char		*buffer;
	size_t		i;
	size_t		len;

	if (!s1)
		return (0);
	len = strlen(s1);
	if ((buffer = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static int		ft_isinset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		len;

	if ((!s1) || (!s1 && !set))
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	j = 0;
	k = strlen(s1);
	while (ft_isinset(s1[j], set))
		j++;
	if (j < k)
		k--;
	while (ft_isinset(s1[k], set))
		k--;
	len = k - j + 1;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = s1[j++];
	return (str);
}



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	int		i;
	size_t	strln;

	if (!s)
		return (NULL);
	if ((int)start < 0)
		return (NULL);
	strln = strlen(s);
	if (len >= (strln - (size_t)start))
		len = strln - (size_t)start;
	if ((size_t)start >= strln)
		len = 0;
	if ((buffer = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (len--)
		buffer[i++] = s[start++];
	buffer[i] = '\0';
	return (buffer);
}



char	*nt_strrchr_modified(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char*)s;
	i = (int)strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i + 1);
		i--;
	}
	return (0);
}



void    ft_putchar(char c)
{
    write(1, &c, 1);
}