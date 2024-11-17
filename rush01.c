/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:09:10 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 17:09:20 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_valid_input(int argc, char **argv, int *clues)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			if (index >= 16)
				return (0);
			clues[index] = argv[1][i] - '0';
			index++;
			i++;
		}
		else if (argv[1][i] == '\0')
			break ;
		else
			return (0);
	}
	if (index != 16)
		return (0);
	return (1);
}

void	print_solution(int **grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			ft_putchar(c);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	check_clues(int **grid, int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col_up(grid, i, clues[i]))
			return (0);
		if (!check_col_down(grid, i, clues[i + 4]))
			return (0);
		if (!check_row_left(grid[i], clues[i + 8]))
			return (0);
		if (!check_row_right(grid[i], clues[i + 12]))
			return (0);
		i++;
	}
	return (1);
}

int	is_safe(int **grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve_puzzle(int **grid, int row, int col, int *clues)
{
	int	num;

	num = 1;
	if (row == 4)
	{
		if (check_clues(grid, clues))
			return (1);
		return (0);
	}
	if (col == 4)
		return (solve_puzzle(grid, row + 1, 0, clues));
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_puzzle(grid, row, col + 1, clues))
				return (1);
		}
		num++;
	}
	grid[row][col] = 0;
	return (0);
}
