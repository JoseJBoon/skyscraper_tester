/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/15 09:40:10 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 20:34:34 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include "rush01.h"
#include "checker.h"

bool	is_output_error(void)
{
	char	buffer[BUF_N];

	if (!read_stdin(buffer, BUF_N))
		return (false);
	if (ft_strcmp(buffer, ERR_MSG) == 0)
		return (true);
	ft_putstr(ERR_NO);
	return (false);
}

bool	validate_sequence(t_skyscraper *sky, int *err_x, int *err_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < sky->size)
	{
		if (!is_unique_row(sky->grid, sky->size, y))
			return (*err_y = y, false);
		++y;
	}
	x = 0;
	while (x < sky->size)
	{
		if (!is_unique_column(sky->grid, x, sky->size))
			return (*err_x = x, false);
		++x;
	}
	return (true);
}

bool	validate_with_clues(t_skyscraper *sky, int *err_x, int *err_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < sky->size)
	{
		if (!row_visible(sky, sky->size - 1, y))
			return (*err_y = y, false);
		++y;
	}
	x = 0;
	while (x < sky->size)
	{
		if (!column_visible(sky, x, sky->size - 1))
			return (*err_x = x, false);
		++x;
	}
	return (true);
}

bool	validate_solution(t_skyscraper *sky)
{
	int	err_x;
	int	err_y;

	err_x = -1;
	err_y = -1;
	if (validate_sequence(sky, &err_x, &err_y)
		&& validate_with_clues(sky, &err_x, &err_y))
		return (true);
	print_grid(sky, err_x, err_y);
	return (false);
}

int	main(int argc, char *argv[])
{
	t_skyscraper	sky;

	if (argc != 2)
		return (!is_output_error());
	if (!validate_and_parse(*(argv + 1), sky.clues, &sky.size))
		return (!is_output_error());
	if (!solve(&sky, 0, 0))
		return (!is_output_error());
	if (!validate_and_parse_grid(&sky))
		return (ft_putstr("Skyscraper grid not properly formatted!\n"));
	if (!validate_solution(&sky))
		return (ft_putstr("Incorrect solution!\n"));
	return (0);
}
