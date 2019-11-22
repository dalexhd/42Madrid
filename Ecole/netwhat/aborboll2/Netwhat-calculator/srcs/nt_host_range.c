/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_host_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:55:57 by lacollar          #+#    #+#             */
/*   Updated: 2019/11/20 13:58:05 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_calculator.h"

int     ntw_len(int cidr)
{
    int len;
    int host_range;

    if (cidr == 25)
        host_range = 126;
    if (cidr == 26)
        host_range = 62;
    if (cidr == 27)
        host_range = 30;
    if (cidr == 28)
        host_range = 14;
    if (cidr == 29)
        host_range = 6;
    if (cidr == 30)
        host_range = 2;
    len = host_range + 2;
    return (len);
}

int     lower_edge(int len, int octet)
{
    int edge;

    edge = 0;
    while (edge <= 255)
    {
        if (octet >= edge && octet <= edge + len - 1)
            return (edge);
		edge += len;
    }
    return (-1);
}

int     upper_edge(int len, int octet)
{
    int edge;

    edge = 0;
    while (edge <= 255)
    {
        if (octet >= edge && octet <= edge + len - 1)
            return (edge + len - 1);
		edge += len;
    }
    return (-1);
}

int     main(int argc, char **argv)
{
    int	l_edge;
    int	u_edge;
	int	cidr;
	int	last_octet;
	int len;
	
	if (argc == 3)
    {
        last_octet = atoi(argv[1]);
		cidr = atoi(argv[2]);
        if (cidr <= 24)
        {
            printf("Host range :\t.1 -  .254\n");
            return (0);
        }
        if (cidr > 30)
        {
            printf("Wrong CIDR\n");
            return (0);
        }
		len = ntw_len(cidr);
		l_edge = lower_edge(len, last_octet);
		u_edge = upper_edge(len, last_octet);
		printf("Host range :\t.%d -  .%d\n", l_edge, u_edge);
        return (0);
    }
    if (argc != 3)
    {
        printf("Please type TWO arguments.");
        return (0);
    }
}