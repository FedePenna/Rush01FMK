/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:15:30 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 22:15:32 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_row_left(int *row, int clue)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i++;
	}
	return (count == clue);
}

int	check_row_right(int *row, int clue)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i--;
	}
	return (count == clue);
}

int	check_col_up(int **grid, int col, int clue)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i++;
	}
	return (count == clue);
}

int	check_col_down(int **grid, int col, int clue)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i--;
	}
	return (count == clue);
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
