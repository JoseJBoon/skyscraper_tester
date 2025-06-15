/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/14 09:50:48 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 15:15:54 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "rush01.h"

static int	write_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

static void	print_solution(int grid[9][9], int n)
{
	int		x;
	int		y;
	char	digit;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			digit = '0' + grid[y][x];
			write(STDOUT_FILENO, &digit, 1);
			if (x != n - 1)
				write(STDOUT_FILENO, " ", 1);
			++x;
		}
		write (STDOUT_FILENO, "\n", 1);
		++y;
	}
}

int	main(int argc, char *argv[])
{
	t_skyscraper	sky;

	if (argc != 2)
		return (write_error());
	if (validate_and_parse(*(argv + 1), sky.clues, &sky.size))
	{
		if (solve(&sky, 0, 0))
		{
			print_solution(sky.grid, sky.size);
			return (0);
		}
	}
	return (write_error());
}
