/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:16:40 by mpisani           #+#    #+#             */
/*   Updated: 2024/11/17 22:17:57 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_error(void);

int		is_valid_input(int argc, char **argv, int *clues);
int		is_safe(int **grid, int row, int col, int num);

int		check_row_left(int *row, int clue);
int		check_row_right(int *row, int clue);
int		check_col_up(int **grid, int col, int clue);
int		check_col_down(int **grid, int col, int clue);
int		check_clues(int **grid, int *clues);

void	print_solution(int **grid);
int		solve_puzzle(int **grid, int row, int col, int *clues);

#endif
