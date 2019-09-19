/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:28:53 by cafernan          #+#    #+#             */
/*   Updated: 2019/09/15 19:34:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
/*
Skyscraper puzzle solver
example input:
    solve ([2,2,1],[1,2,2],[3,1,2],[2,1,3])
solution:
    [[1,2,3],[3,1,2],[2,3,1]]
diagram of above puzzle:
    | 2 | 2 | 1 | [1]=>
 ___|___|___|___|___
  3 | 1 | 2 | 3 | 1
 ___|___|___|___|___
  1 | 3 | 1 | 2 | 2
 ___|___|___|___|___
  2 | 2 | 3 | 1 | 2
 ___|___|___|___|___
    | 2 | 1 | 3 |
    |   |   |   | [2]=>
*/

void	ft_printstr(char *str);
void	ft_getavailable(char *c, int i, int sudoku[][4]);
void	ft_checktop(char *a, int sudoku[][4]);
void	ft_checkbottom(char *a, int sudoku[][4]);
void	ft_checkleft(char *a, int sudoku[][4]);
void	ft_checkright(char *a, int sudoku[][4]);
void	deleteSpaces(char src[], char dst[]);
void	ft_fixleft(char *a, int sudoku[][4]);
void	ft_fixright(char *a, int sudoku[][4]);
void	ft_fixtop(char *a, int sudoku[][4]);
void	ft_fixbottom(char *a, int sudoku[][4]);
void	ft_printsudoku(char *a, int sudoku[][4]);



void	rush(char **argv)
{
	int	i;
	int	sudoku[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	char	dest[16];

	deleteSpaces(argv[1], dest);
	ft_checktop(dest, sudoku);
	ft_checkbottom(dest, sudoku);
	ft_checkleft(dest, sudoku);
	ft_checkright(dest, sudoku);
	ft_fixleft(dest, sudoku);
	ft_fixleft(dest, sudoku);
	ft_fixright(dest, sudoku);
	ft_fixtop(dest, sudoku);
	ft_fixbottom(dest, sudoku);
	ft_printsudoku(dest, sudoku);
}


