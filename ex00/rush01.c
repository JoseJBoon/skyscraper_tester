/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush01.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/14 16:51:59 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 13:57:17 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "rush01.h"

bool	is_unique_column(int grid[9][9], int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = i + 1;
		while (j < y)
		{
			if (grid[i][x] == grid[j][x])
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

bool	is_unique_row(int grid[9][9], int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = i + 1;
		while (j < x)
		{
			if (grid[y][i] == grid[y][j])
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

bool	row_visible(t_skyscraper *sky, int x, int y)
{
	int	i;
	int	heights[2];
	int	left;
	int	right;

	i = 0;
	heights[0] = 0;
	heights[1] = 0;
	left = *(sky->clues + sky->size * 2 + y);
	right = *(sky->clues + sky->size * 3 + y);
	while (i < sky->size)
	{
		if (sky->grid[y][i] > heights[0])
		{
			heights[0] = sky->grid[y][i];
			--left;
		}
		if (sky->grid[y][x - i] > heights[1])
		{
			heights[1] = sky->grid[y][x - i];
			--right;
		}
		++i;
	}
	return (left == 0 && right == 0);
}

bool	column_visible(t_skyscraper *sky, int x, int y)
{
	int	i;
	int	heights[2];
	int	top;
	int	bottom;

	i = 0;
	heights[0] = 0;
	heights[1] = 0;
	top = *(sky->clues + x);
	bottom = *(sky->clues + sky->size + x);
	while (i < sky->size)
	{
		if (sky->grid[i][x] > heights[0])
		{
			heights[0] = sky->grid[i][x];
			--top;
		}
		if (sky->grid[y - i][x] > heights[1])
		{
			heights[1] = sky->grid[y - i][x];
			--bottom;
		}
		++i;
	}
	return (top == 0 && bottom == 0);
}

bool	solve(t_skyscraper *sky, int x, int y)
{
	int	tower;

	if (y == sky->size)
		return (true);
	tower = 1;
	while (tower <= sky->size)
	{
		sky->grid[y][x] = tower;
		if (is_unique_column(sky->grid, x, y + 1)
			&& is_unique_row(sky->grid, x + 1, y)
			&& (x + 1 < sky->size || row_visible(sky, x, y))
			&& (y + 1 < sky->size || column_visible(sky, x, y))
			&& ((x + 1 == sky->size && solve(sky, 0, y + 1))
				|| (x + 1 < sky->size && solve(sky, x + 1, y))))
			return (true);
		++tower;
	}
	return (false);
}
