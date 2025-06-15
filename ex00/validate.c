/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/14 16:47:55 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/14 23:56:43 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	validate_count(int count)
{
	if (count >= 16 && count <= 36 && count % 4 == 0)
		return (count / 4);
	return (0);
}

static bool	validate_clues(int clues[36], int n)
{
	int	i;

	i = 0;
	while (i < (n * 4))
	{
		if (clues[i] > n)
			return (false);
		++i;
	}
	return (true);
}

bool	validate_and_parse(char *arg, int clues[36], int *n)
{
	int	count;
	int	is_space;

	count = 0;
	is_space = 1;
	while (*arg)
	{
		if (!ft_isspace(*arg))
		{
			if (!ft_isdigit(*arg) || *arg == '0' || count == 36
				|| is_space == 0)
				return (false);
			clues[count++] = *arg - '0';
			is_space = 0;
		}
		is_space = 1;
		++arg;
	}
	*n = validate_count(count);
	return (*n != 0 && validate_clues(clues, *n));
}
