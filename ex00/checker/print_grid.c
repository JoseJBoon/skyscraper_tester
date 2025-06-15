/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/15 17:20:34 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 17:23:04 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include "checker.h"

static void	print_row_clues(int *clues, int size)
{
	int	i;

	i = 0;
	ft_putstr("  ");
	while (i < size)
	{
		ft_putchar('0' + clues[i]);
		if (i < (size - 1))
			ft_putchar(' ');
		++i;
	}
	ft_putchar('\n');
}

static void	print_column_clue(int *clues, int y)
{
	ft_putchar('0' + clues[y]);
	ft_putchar(' ');
}

static void	print_err_row_solution(t_skyscraper *sky, int row, int err_x)
{
	int	x;

	x = 0;
	while (x < sky->size)
	{
		if (x == err_x)
			ft_putstr(C_RED);
		ft_putchar('0' + sky->grid[row][x]);
		ft_putchar(' ');
		if (x == err_x)
			ft_putstr(C_CLR);
		++x;
	}
}

void	print_grid(t_skyscraper *sky, int err_x, int err_y)
{
	int	y;

	y = 0;
	print_row_clues(sky->clues, sky->size);
	while (y < sky->size)
	{
		print_column_clue(sky->clues + sky->size * 2, y);
		if (y == err_y)
			ft_putstr(C_RED);
		print_err_row_solution(sky, err_y, err_x);
		if (y == err_y)
			ft_putstr(C_CLR);
		print_column_clue(sky->clues + sky->size * 3, y);
		ft_putchar('\n');
		++y;
	}
	print_row_clues(sky->clues + sky->size, sky->size);
}
