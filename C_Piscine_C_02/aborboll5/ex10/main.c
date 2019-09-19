/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:13:58 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/12 19:25:48 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int			main(void)
{
	char			src[] = "ZnayMJYniPbGk <=> 19DmKVV <=> 8dhmXjjVPV <=> 9UtwVBTO <=> 7ZjxPTDiehubcSJPypzQ <=> 19CNwAdAdseMglXObidxO <=> 19bOymOeNrDElIj <=> 13UYRvlmazCmvcuBrVKL <=> 18zw <=> 9Ha <=> 2XCIszTYSTvFRfF <=> 20vTURCSlxwFSrpnX <=> 15Z <=> 1lTdXiqTFimFH <=> 12vYgujXjPyGX <=> 11WbnqeaeIxtggkcXZgdmN <=> 20UM <=> 2b <=> 1dBEBVnaS <=> 8uAUUJ <=> 5uISVO <=> 10AmOhBFfEyw <=> 11GbDyZ <=> 5 <=> 8rLfxzjIShEJkH <=> 13dJsKvugZOfmqzyprDO <=> 18H <=> 1zdeiPzBtmNQ <=> 11byaVwFqS <=> 8IVlcRltwDPBBuJFak <=> 17j <=> 1BvluNkieBtZgs <=> 13rI <=> 2IntSWJ <=> 6ZjVIXazZRsyVLm <=> 14Vox <=> 3rg <=> 2Pb <=> 16osoNxnaQe <=> 9yOlbvTBPnppA <=> 12cmu <=> 10NrqKFQr <=> 7gyEXubDiyFEAs <=> 16oJIxF <=> 5SFgCUylrEUAHMfrRxh <=> 18CnbEzpYVgWba <=> 12yGzXELwZfAVxKUCcWda <=> 19MJNN <=> 15PHdk <=> 11GffiZpcfNqjP <=> 12GwjUXauin <=> 18JnJQgYhchCQkKVXuHAom <=> 20zUnMrx <=> 6QgmABXuxnkxvxtphAB <=> 18WFhbxvpnRDMz <=> 18oOHA <=> 4GDSSx <=> 5XTdWGCAfIpwE <=> 13xDm <=> 3bIvOEq <=> 6pZhAGrR <=> 13VsPaPFkmJBWDWNvbbqiZ <=> 20 <=> 5LxuffZcht <=> 19m ZJ <=> 7JkZW <=> 4kqHhTSe <=> 7hiZWRGRlWIDU <=> 12PZRyyyp <=> 13po <=> 16mJzoosZgsaZtlSeUhZS <=> 19dmZslp <=> 6tshxAM <=> 10rzsEXCwdr <=> 9dzujJbUWukU <=> 14cIQSGhvXg <=> 20xeDuqeqPmcHOuWqH <=> 16kIKkWriVPO <=> 10LscRynwx <=> 8KfyXXVMiVN <=> 10NQDXafzkYOqTjWkhu <=> 17 <=> 18kNDzRPTWZ <=> 9UpcXtbTzJziGzlbNg <=> 17NIQBEdJZmKmSg <=> 13x <=> 1Cr <=> 9LzDf <=> 4h <=> 1ulsnpUOPiECkLsLwV <=> 17VjIwAuJxQIpHEEFP <=> 16TfusMNLwIeHBqPhXCKuo <=> 20LfRAfteSqNLNrQctadrq <=> 20nklsCtBtCHTN <=> 12tXXRbyazHK <=> 11SUJZTsrs <=> 8exDcg <=> 5pPcyNpJyjtHq <=> 12LWnPmqqpsIRUuM <=> 14012345678 <=> 10abcdefgh <=> 10;[]'/.,_-) <=> 10 <=> 0 <=> 10";
	char			dest[] = "";
	unsigned int	size = 170;
	printf("%i characters \tOutput >>> \"%s\"", ft_strlcpy(dest, src, size), dest);
	return (0);
}
