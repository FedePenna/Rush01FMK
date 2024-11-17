/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:15:43 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 22:15:48 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_valid_input(int argc, char **argv, int *clues)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] && index < 16)
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			clues[index++] = argv[1][i++] - '0';
			if (argv[1][i] != ' ' && argv[1][i] != '\0')
				return (0);
		}
		else if (argv[1][i])
			return (0);
	}
	if (index != 16 || argv[1][i])
		return (0);
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
