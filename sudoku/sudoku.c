/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:30:33 by mmoros            #+#    #+#             */
/*   Updated: 2018/01/21 01:30:00 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_puzzle(int **puzzle)
{
	int x;
	int y;

	x = 0;
	y = 0;
	write(1, "| - - - - - - - - - - - |\n", 26);
	while(y < 9)
	{
		x = 0;
		write(1, "| ", 2);
		while (x < 9)
		{
			ft_putchar('0' + puzzle[x][y]);
			ft_putchar(' ');
			x++;
			if (x % 3 == 0 && x != 9)
				write(1, "| ",2);
		}
		y++;
		write(1, "|\n", 2);
		if (y % 3 == 0 && y != 9)
			write(1, "| - - - * - - - * - - - |\n", 26);
	}
	write(1, "| - - - - - - - - - - - |\n", 26);
}

int		ft_check_if_valid(int **puzzle, int x, int y, int try) //Checks if the provided attempt is a valid move
{
	int i;
	int minor_x;
	int minor_y;
	
	printf("X = %d, Y = %d, try = %d\n", x, y, try);

	minor_x = (x / 3) * 3;	//Computes x and y of top left corner in minor square
	minor_y = (y / 3) * 3;
	i = -1;
	while (++i < 9) //Checks row
		if (puzzle[i][y] == try)
			return (0);
	i = -1;
	while (++i < 9) //Checks column
		if (puzzle[x][i] == try)
			return (0);
	i = -1;
	while (++i < 9) //Checks minor square
		if (puzzle[(i % 3) + minor_x][(i / 3) + minor_y] == try)
			return (0);
	return (1); //Is a valid try! :D
}	//Returns (1) if the new placement is valid. Otherwise, (0)

int		ft_next_empty_square(int **puzzle)
{
	int x;
	int y;

	y = 0;
	while (y < 9) //Incramenting through rows
	{
		x = 0;
		while (x < 9) //Checking each square in row
		{
			if (puzzle[x][y] == 0)
				return (x + y * 9);
			x++;
		}
		y++;
	}
	return (81);//Returns 81 if puzzle is solved!! (outside dimensions of puzzle array)
}	//Returns x and y coordinate of next empty square. output = x + 9*y

void	sudoku(int **puzzle, int *solved)
{
	int next_x;
	int next_y;
	int i;
	
	next_y = ft_next_empty_square(puzzle);
	next_x = next_y % 9;
	next_y /= 9;
	if (next_y < 9) //Puzzle solved if next_y = 9
	{
		i = 0;
		while (i < 9 && *solved == 0) //Trying all possible numbers and checking if puzzle is solved
		{
			if (ft_check_if_valid(puzzle, next_x, next_y, i + 1) == 1)
			{
				puzzle[next_x][next_y] = i + 1;
				sudoku(puzzle, solved);
				if (*solved == 0)	//Checking if the current move was unsuccessful
					puzzle[next_x][next_y] = 0; //Reset square to 0 if unsuccessful move
			}
			i++;
		}
	} else
		*solved = 1;
}

int		main(int argc, char **argv)
{
	int **puzzle;
	int *solved;
	int i;
	int j;

	if (argc == 10) //Ensuring correct number of arguments
	{
		solved = (int*)malloc(sizeof(int)); //Allocating space for SOLVED
		*solved = 0;
		i = 0;
		puzzle = (int**)malloc(sizeof(int*) * 9); //Allocating space for PUZZLE
		while (i < 9)
			puzzle[i++] = (int*)malloc(sizeof(int) * 9);
		i = -1;
		while (--i < 9) //Turning input data into int puzzle array
		{
			j = -1;
			while (++j < 9)
				if (argv[i + 1][j] != '.')
					puzzle[i][j] = argv[i + 1][j] - '0';
				else
					puzzle[i][j] = 0;
		}
		ft_print_puzzle(puzzle); //Unsolved
		sudoku(puzzle, solved);
		if (ft_next_empty_square(puzzle) == 81)	
			ft_print_puzzle(puzzle); //Solved
		else
			write(1, "Error\n", 6);
	} else
		write(1, "Error\n", 6);
	return (0);
}
