/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush01.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/14 23:59:21 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 20:15:28 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdbool.h>

typedef struct s_skyscraper
{
	int	grid[9][9];
	int	clues[36];
	int	size;
}	t_skyscraper;

bool	is_unique_column(int grid[9][9], int x, int y);
bool	is_unique_row(int grid[9][9], int x, int y);
bool	row_visible(t_skyscraper *sky, int x, int y);
bool	column_visible(t_skyscraper *sky, int x, int y);
bool	validate_and_parse(char *arg, int clues[36], int *n);
bool	solve(t_skyscraper *sky, int x, int y);

#endif
