/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:16:18 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 22:16:22 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	solve_puzzle(int **grid, int row, int col, int *clues)
{
	int	num;

	if (row == 4)
		return (check_clues(grid, clues));
	if (col == 4)
		return (solve_puzzle(grid, row + 1, 0, clues));
	num = 1;
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

void	initialize_grid(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		grid[i] = (int *)malloc(sizeof(int) * 4);
		if (!grid[i])
			exit(1);
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;

	clues = (int *)malloc(sizeof(int) * 16);
	if (!clues)
		return (1);
	if (!is_valid_input(argc, argv, clues))
		return (ft_error());
	grid = (int **)malloc(sizeof(int *) * 4);
	if (!grid)
	{
		free(clues);
		return (1);
	}
	initialize_grid(grid);
	if (solve_puzzle(grid, 0, 0, clues))
		print_solution(grid);
	else
		ft_error();
	while (argc-- && grid[argc])
		free(grid[argc]);
	free(grid);
	free(clues);
	return (0);
}
