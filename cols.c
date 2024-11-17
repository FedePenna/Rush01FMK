/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cols.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:34:14 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 17:34:21 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
