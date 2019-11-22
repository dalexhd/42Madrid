/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:39:23 by cafernan          #+#    #+#             */
/*   Updated: 2019/09/15 21:31:19 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}


int random_range(int min_value, int max_value)
{
	return rand();
}

void	ft_printrand(int x, int y)
{
	printf("El numero random es: %i\n", random_range(0, 4));
}

void	ft_printsudoku(char *a, int sudoku[][4])
{
	printf("\n    %c   %c   %c   %c\n    -------------\n%c  {%i | %i | %i | %i}  %c\n    -------------\n%c  {%i | %i | %i | %i}  %c\n    -------------\n%c  {%i | %i | %i | %i}  %c\n    -------------\n%c  {%i | %i | %i | %i}  %c\n    -------------\n    %c   %c   %c   %c\n\n'''''''',,,,,,,,,,,,,,;:ccccccclllllllllllllllll:;;;;;;;;;;;;;;;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,,,,,'''\n'''',,,,,,,,,,,,,,,,,;:cllclllllcc:;'..........''''',,;;;;;;;;;;;;;;;;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,,\n'',,,,,,,,,,,,,,,,,;:clllllcc:,'..                   ..',;;;;;;;;;;;;;;;;;;;;;;;;;,,,,,,,,,,,,,,,,,,\n,,,,,,,,,,,,,,,,,,;:cllllc:'.                            .';;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,,,,,,,,,,,\n,,,,,,,,,,,,,,,,;;cllll:,.                ......           ..,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,,,,,\n,,,,,,,,,,,,;;;;:clll:'.                 ..,;;'.             ..;:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,,\n,,,,,,,,,,;;;;;:cllc,.                    .','...              .,;:::;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,\n,,,,,,,;,;;;;:clll:.           ..................... .          .,::::::::::::::;;;;;;;;;;;;;;;;;;;;\n,,,,,,;;;;;;:cllc,.       ..'';::cccclloolcc::;,''...''.''',,'.  .;::::::::::::::::::;;;;;;;;;;;;;;;\n,,,,;;;;;;;:lloc,.      .,:cloodddxxxxxxxxkkkxxxdddooooooooolc;.. .;:::::::::::::::::::::;;;;;;;;;;;\n,;;;;;;;;;clool;.     .':looddxxxxxkkkkkkkkkkkkkkkkkkxxxxdddoolc,. .;::::::::::::::::::::::::;;;;;;;\n;;;;;;;;:cloooc.     ..;lodddxxxkkkkOOOOOOOOOOOOOOOkkkkkxxxddool:'  .:c::::::::::::::::::::::::;;;;;\n;;;;;;;:looooo;.    ..':loddxxkkkkOOOOOOOOOOOOOOOOOOkkkkkxxxddolc,. .;ccccccc::::::::::::::::::::;;;\n;;;;;;cloooooc'.     .';loddxkkkOOOOOOOOOOOOOOOOOOOOOOOkkkxxxdooc,  .,cccccccccccc::::::::::::::::::\n;;;;:cloollllc.   ..  .,codxxkkOOOOOO00000000OOOO00OOOOOOkkxxddoc,   ':ccccccccccccccc::::::::::::::\n;;;;:clllooool,..     .,lddxxkOOOOOO0000000000000000OOOkkkxxxddol,  .,ccccccccccccccccccc:::::::::::\n;;;;:::::cllll:.      .;oddxxxxxxxxxdoooxkkO00O00OOOkxoc::;;;:cll,  .;lcccccccccccccccccccc:::::::::\n;;;;:::::::cllc.      .:ddddolc:;;;'...,:ldxkOOOkkxxdc,........':,  .;lllllccccccccccccccccccc::::::\n;;;;;::::::::cc,.     'ldddoc::::cc::c:cllodxkkkxdolc:;:clolc:;,,,. .;lllllllcccccccccccccccccc:::::\n;;;:::::::::clool:.. .'cloodddollc:;;:cllooodkOOkolc:;:c;;;::;;:;,...:llllllllllccccccccccccccccc:::\n;;::::::cc:cllldxd:. .;ooooolllccc:;;ldolodooxO0Odccc:coc;;cc;;c:;'.,;:llllllllllllccccccccccccccccc\n;;:::::::ccclodxkxo,..:dxxkkxdddddxdoddddxxook0KKkdlcllodooooooool;.,cclllllllllllllllcccccccccccccc\n;::::::::cccldxxxoc;.'lxxxkkOkkkkkkkkkkOOOkdxOKKK0Oxlldxkkkkkkkxxdc.,lollllllllllllllllllccccccccccc\n::::::::::ccldxdolc;';oxxkkOOOOOOkkkkkkOOOO000KXXK0OxddxkOOOOOkkxdl,,lollooolllllllllllllllccccccccc\n::::::::::ccloxdodl;,:ldxkOO000KKKKKKK00KK00KKKXXKK0kxxkO0KKK00Okxo;;looooolllllllllllllllllcccccccc\n::::::::::cccldxxxo;,:ldkOO00KKXXKKKKKK00KK0KKXXXXKKOkxxk0KKKKK0Okd:;looooooolllllllllllllllllcccccc\n:::::::::::ccloxxkd;';cdkOOO00KKKKK00OOOO0KKKKXNNXXK0kxxddkO0000Oxd:;looooooooollllllllllllllccccccc\n:::::::::ccccclldxd;',:oxkkOOO000OOkkkOOOOOOkk0KKKK0xooddoooxOOOkxo:;loooooooooooooollllllllllcccccc\n::::::::::ccccllcll;'';coxxkkkkOOkxdxkOOkxdl;;cooool,.':lolccodxdol;;loooooooooooollllllllllllcccccc\n::::::::::ccccclccc:'',:loodxxkkxocclodolcc;'...,,'.....,;,,',coll:';looooooooooooolllllllllllllcccc\n:::::::::cccccccllcc,..,:cclldxkd:''';::;;;;,,,;::;,''........:lc;'.;ooooooooooooooollllllllllllcccc\n:::::::::ccccccclllc:'..,;:;:coxxl::llloddddxxkxkkxdolc:;:lc;;c:,..'coooooooooooooollllllllllllllccc\n:::::::::ccccccccllcc;...';,,;:ldxodO0OOOkkO00KKKK00kxdddxkdlc;,...:oooooooooooooooolllllllllllllccc\n:::::::::ccccccccllllc,...',,,;:lddxO0KK000000OO00OOkxddxxxdl;'...:odooooooooooooooolllllllllllllccc\n::::::::::ccccccccllllc,....',;:coodk0KK0Okxddddoooollloxxdc;...'codooooooooooooooooollllllllllllccc\n::::::::::ccccccccclllll,.. ..',:codxk0KKOxollc:;;;;;cldkxo;...'cdddddooooooooooooooolllllllllllcccc\nc::::::::cccccccccclllodl'.   ..';clodk0KK00Okdlllllloxkko:'.'ldddodddddooooooooooooollllllllllllccc\nxoc::::::ccccccccccclodxo;.    ...',:ldkOO00Okxollloodddl;'';oO0xoooooooodoooooooooolllllllllllllccc\noddlc:::::cccccccccclodxxc.       ...';:clooolc:;;;;:::;..'codxOkdooooooooooooooooolllllllllllllcccc\n::ccc::::cccllllcc:codxxxd:'...       ...''''............,lodddxkdooooooooooooooooolllllllllllllcccc\n:::::cloooooooc,'.,lxxxkkkxoc:;,'.....     .         ..;coooooodxxoooooooooooooooooolllllllllllccccc\n;:cldxdol:,.....  .;oxkkkOOOkxxdolc:;,'.....    .....,:oooooooooddooooooooooooolllooollllllllllccccc\n:ldkkdood:.         .;oxOO000OOOkxdolc:::::ccc::;;;:cccoxdoooooooooooooooooooollllllllllllllllcccccc\ndkkkxddxOkl.          .'cdk000000OOkxxdddddxxxdollllll,,dOkdoooooooooooooooooollllllllllllllllcccccc\nkkkkxxxkOOOx;.           .':ldkO00OOOkkxxxxxxxddoolll:..:xOOkxddddddddooooollollllllllllllllllcccccc\nkkkkkkkkOOO0Oo'              ..;cldxkkkkkkkkkxxdolllc'  .;dkO0OOkkkkkkxxxxxdollllllllllllllccccccccc\nkkkkkkkkOOOOOOkc.                 ..',:ccllooolc:;;,..    'lkO000OOOOOkOOOOOxdolllllllllllcccccccccc\nkkkkkkkkOOOOOOOOx;.                                        .:x00000OOOOOO000Okxxdoolllllcccccccccccc\nxkkkkkkkkkOOOOOO0kl.                                         ,d0KK00O00000K0Okxkkkxxdolccccccccccccc\nxxkkkkkkkkkkOOOOO0Ol.                                         ;kKK0000000KK00kkkOOkkkxolccccccccccc: We tried it a lot 😭 You are the best man!\n", a[0], a[1], a[2], a[3], a[8], sudoku[0][0], sudoku[0][1], sudoku[0][2], sudoku[0][3], a[12], a[9], sudoku[1][0], sudoku[1][1], sudoku[1][2], sudoku[1][3], a[13], a[10], sudoku[2][0], sudoku[2][1], sudoku[2][2], sudoku[2][3], a[14], a[11], sudoku[3][0], sudoku[3][1], sudoku[3][2], sudoku[3][3], a[15], a[4], a[5], a[6], a[7]);
}

void	ft_getavailable(char *c, int i, int sudoku[][4])
{
	printf("La i es: %s\nEl num es: %i\nEl sudoku es: %i\n", c, i, sudoku[3][3]);
}

void deleteSpaces(char src[], char dst[]){
	int s;
	int d;

	d = 0;
	s = 0;
	while (src[s] != 0)
	{
		if (src[s] != ' ') {
			dst[d] = src[s];
			d++;
		}
		s++;
	}
  	dst[d] = '\0';
}

void	ft_checktop(char *a, int sudoku[][4])
{

	int i;
	int c;
	printf("");
	i = 0;
	while (i < 4)
	{
		if (a[i] == '4')
		{
			c = 0;
			while (c < 4)
			{
				sudoku[c][i] = c+1;
				//printf("1 => c:%i i:%i\n", c, i);
				c++;
			}
		}
		else if (a[i] == '1')
		{
			c = 0;
			//printf("1 => c:%i i:%i\n", c, i);
			sudoku[c][i] = 4;
		}
		i++;
	}
	//ft_printsudoku(a, sudoku);
}

void	ft_checkbottom(char *a, int sudoku[][4])
{

	int i;
	int c;

	i = 0;
	while (i < 4)
	{
		if (a[i + 4] == '4')
		{
			c = 4;
			while (c > 0)
			{
				sudoku[c][i] = 4 - c;
				//printf("2 => c:%i i:%i\n", c, i + 4);
				c--;
			}
		}
		else if (a[i + 4] == '1')
		{
			c = 3;
			//printf("2 => c:%i i:%i\n", c, i + 4);
			sudoku[c][i] = 4;
		}
		i++;
	}
	//ft_printsudoku(a, sudoku);
}

void	ft_checkleft(char *a, int sudoku[][4])
{

	int i;
	int c;

	i = 0;
	while (i < 4)
	{
		if (a[i + 8] == '4')
		{
			c = 0;
			while (c < 4)
			{
				sudoku[i][c] = c+1;
				//printf("3 => c-2:%i i:%i\n", c, i + 8);
				c++;
			}
		}
		else if (a[i + 8] == '1')
		{
				//printf("3 => c-3:%i i:%i\n", c, i + 8);
				sudoku[i][0] = 4;
		}
		i++;
	}
	//ft_printsudoku(a, sudoku);
}

void	ft_checkright(char *a, int sudoku[][4])
{

	int i;
	int c;

	i = 0;
	while (i < 4)
	{
		if (a[i + 12] == '4')
		{
			c = 3;
			while (c >= 0)
			{
				sudoku[i][c] = 4 - c;
				//printf("4,2 => c:%i i:%i\n", c, i + 12);
				c--;
			}
		}
		else if (a[i + 12] == '1')
		{
				//printf("4,3 => c:%i i:%i\n", c, i + 12);
				sudoku[i][3] = 4;
		}
		i++;
	}
	//ft_printsudoku(a, sudoku);
}

void	ft_fixleft(char *a, int sudoku[][4])
{

	int i;
	int c;
	int e;

	i = 0;
	while (i < 4)
	{
		if (a[i + 8] == '3')
		{
			c = 0;
			while (c < 4)
			{
				if (sudoku[c][i] == 2)
				{
					e = 1;
					while (e < 3)
					{
						sudoku[c + 1][e] = e  + 2;
						e++;
					}
				}
				c++;
			}
		}
		if (a[i + 8] == '2')
		{
			if (sudoku[0][1] ==  4)
			{
				sudoku[c][2] = 10 - sudoku[c][3] - sudoku[c][1] - sudoku[c][1];
			}
		}
		i++;
	}
	//ft_printsudoku(a, sudoku);
}

void	ft_fixright(char *a, int sudoku[][4])
{

	int i;
	int c;
	int e;

	i = 0;
	while (i < 4)
	{
		if (a[i + 12] == '3')
		{
			//printf("1");
			c = 0;
			while (c < 4)
			{
				//printf("2");
				if (sudoku[c][i] == 2)
				{
					e = 1;
					while (e < 3)
					{
						sudoku[c][e] = e + 1;
						e++;
					}
				}
				c++;
			}
		}
		if (a[i + 12] == '2')
		{
			c = 0;
			while (c < 4)
			{
				//printf("2");
				if (sudoku[c][2] == 4)
				{
					sudoku[c][3] = 10 - sudoku[c][0] - sudoku[c][1] - sudoku[c][2];
				}
				if ((sudoku[0][c] + sudoku[1][c] == 7) && sudoku[2][c] == 0 && sudoku[3][c] == 0)
				{
					sudoku[c][3] = 2;
				}

				c++;
			}
		}
		i++;
	}
	//ft_printsudoku(a, sudoku);
}


void	ft_fixtop(char *a, int sudoku[][4])
{

	int i;
	int c;
	i = 0;
	while (i < 4)
	{
		if (a[i] == '3')
		{
			if (sudoku[0][i] == 2 && sudoku[1][i] == 3)
			{
				sudoku[2][i] = 4;
			}
		}
		i++;
	}
}

void	ft_fixbottom(char *a, int sudoku[][4])
{

	int i;
	int c;


	i = 0;
	while (i < 4)
	{

		if (a[i] == '3' && sudoku[0][i] == 2 && sudoku[1][i] == 3)
		{
			sudoku[2][i] = 4;
		}


		if (sudoku[0][i] != 0 && sudoku[1][i] != 0 && sudoku[2][i] != 0 && sudoku[3][i] == 0)
		{
			sudoku[3][i] = 10 - sudoku[0][i] - sudoku[1][i] - sudoku[2][i];
		}
		i++;
	}
}
