/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/15 20:05:03 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 20:35:16 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "rush01.h"
#include "checker.h"

static bool	handle_space(t_source *src, char c, int size)
{
	if (c != ' ' && c != '\n')
		return (false);
	if (src->is_space == 1)
		return (!ft_putstr(ERR_SPC));
	src->is_space = 1;
	if (c != '\n')
		return (true);
	if (src->cur_x != size)
		return (!ft_putstr(ERR_NOX));
	src->cur_x = 0;
	src->cur_y += 1;
	return (true);
}

static bool	handle_digit(t_source *src, t_skyscraper *sky, char c)
{
	if (c < '1' || c > '0' + sky->size || src->is_space == 0)
		return (!ft_putstr(ERR_CHR));
	src->is_space = 0;
	if (src->cur_x < sky->size && src->cur_y < sky->size)
		sky->grid[src->cur_y][src->cur_x] = c - '0';
	src->cur_x += 1;
	return (true);
}

static bool	check_bounds(t_source *src, t_skyscraper *sky)
{
	if (src->cur_x > sky->size)
		return (!ft_putstr(ERR_NOX));
	else if (src->cur_y > sky->size)
		return (!ft_putstr(ERR_NOY));
	return (true);
}

bool	validate_and_parse_grid(t_skyscraper *sky)
{
	t_source	src;

	src = (t_source){0};
	if (read_stdin(src.buffer, BUF_N) == -1)
		return (!ft_putstr(ERR_RD));
	src.is_space = 1;
	while (src.buffer[src.cur])
	{
		if ((handle_space(&src, src.buffer[src.cur], sky->size)
				|| handle_digit(&src, sky, src.buffer[src.cur]))
			&& check_bounds(&src, sky))
			src.cur += 1;
		else
			return (false);
	}
	if (src.cur_y < sky->size)
		return (!ft_putstr(ERR_NOY));
	return (true);
}
