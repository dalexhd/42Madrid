/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_ntw_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:39:33 by lacollar          #+#    #+#             */
/*   Updated: 2019/11/20 14:11:41 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_calculator.h"
#include "netwhat_calculator_utils.c"

char class(char *nbr)
{
	int a = atoi(nbr);

	if (a >= 0 && a <= 127)
		return 'A';
	else if (a >= 128 && a <191 )
		return 'B';
	else if (a >=192 && a <= 223)
		return 'C';
	else if (a >= 224 && a <= 239)
		return 'D';
	else 
		return 'E';
}

int	*to_bin(char **str)
{
	int *re = malloc(sizeof(int) * 32);	
	int a;
	int b;
	int c;
	int d;
	int i = 0;

	if (!str)
		return 0;
	a = atoi(str[0]);
	b = atoi(str[1]);
	c = atoi(str[2]);
	d = atoi(str[3]);

	i = 8;
	while (i-- > 0)
	{
		re[i] = a % 2;
		a /= 2;
	}
	i = 16;
	while (i-- > 8)
	{
		re[i] = b % 2;
		b /= 2;
	}
	i = 24;
	while (i-- > 16)
	{
		re[i] = c % 2;
		c /= 2;
	}
	i = 32;
	while (i-- > 24)
	{
		re[i] = d % 2;
		d /= 2;
	}
	return re;

}

int *to_dec(int *bin)
{
	int *re = malloc(sizeof(int) * 4);
	int i;
	int j;

	if (!bin)
		return 0;
		i = 0;
	j = 0;
	bzero(re, sizeof(int) * 4);
	int k  = 7;
	while (i < 8)
	{
		re[j] = pow(2, k) *  bin[i]  + re[j] ;
		k--;
		i++;
	}
	j++;
	k= 7;
	while (i < 16)
	{	
		re[j] = pow(2, k) *  bin[i]  + re[j] ;
		i++;
		k--;
	}
	j++;
	k = 7;
	while (i < 24)
	{	
		re[j] = pow(2, k) *  bin[i]  + re[j] ;
		k--;
		i++;
	}
	j++;
	k  = 7;
	while (i < 32)
	{	
		re[j] = pow(2, k) *  bin[i]  + re[j] ;
		i++;
		k--;
	}
	return re;

}

void nt_ntw_adr(char *address)
{
	char	**octet;
	char	*suffix;
	char	*ip;
	int		CIDR;
	int		i;
	int		len;
	int		*net_bin;
	int		*bor_bin;
	int		*network_addr;
	int		*broadcast_addr;
	int		*adr;
	net_bin = malloc(sizeof(int) * 32);
	bor_bin  = malloc(sizeof(int) * 32);


	if (!(suffix = malloc(sizeof(char) * 3)))
		return ; 
	len =   suffix - address - 1;
	suffix = nt_strrchr_modified(address, '/');	
	ip = ft_substr(address, 0, len);
	if (!(octet = malloc(sizeof(char*) * 4)))
		return ;
	octet = ft_split(ip, '.');
	CIDR = atoi(suffix);
	i = 0;
	adr = to_bin(octet);
	for (i = 0; i <= CIDR; i++)
	{
		bor_bin[i] = adr[i];
		net_bin[i] = adr[i];
	}
	for (i = CIDR   ; i <= 31  ;i++)
	{
		bor_bin[i] = 1;
		net_bin[i] = 0;
	}
	
	network_addr = to_dec(net_bin);  
	broadcast_addr = to_dec(bor_bin);

	i = 0;
	printf("Network Adress :");
	while (i < 4)
	{
		printf("%d%s",network_addr[i],(i != 3)?".":"");
		i++;
	}
	
	printf("\nbroadcast : ");
	i = 0;
	while (i < 4)
	{
		printf("%d%s",broadcast_addr[i],(i != 3)?".":"");
		i++;
	}
}

int 	main(int argc, char **argv)
{
    if (argc == 2)
    {
		nt_ntw_adr(argv[1]);
		return (0);
    }
	return (0);
}
