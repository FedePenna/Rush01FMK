/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:35:08 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 17:37:24 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;
	int	i;
	int	j;

	i = 0;
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
	while (i < 4)
	{
		grid[i] = (int *)malloc(sizeof(int) * 4);
		if (!grid[i])
			return (1);
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (solve_puzzle(grid, 0, 0, clues))
		print_solution(grid);
	else
		ft_error();
	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	free(clues);
	return (0);
}
