/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:34:29 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 17:34:46 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
