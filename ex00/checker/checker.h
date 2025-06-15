/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/15 15:12:11 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 20:34:45 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stddef.h>

# define ERR_ARG	"Invalid number of arguments!\n"
# define ERR_VAL	"Invalid clues!\n"
# define ERR_RD		"Failed to read from the stdin!\n"
# define ERR_EMP	"Nothing was printed to the stdout!\n"
# define ERR_NO		"`Error` was not printed!\n"
# define ERR_SPC	"Improper format of spaces or newlines!\n"
# define ERR_NOX	"Invalid number of columns!\n"
# define ERR_NOY	"Invalid number of rows!\n"
# define ERR_CHR	"Invalid character at position!\n"
# define ERR_MSG	"Error\n"

# define C_RED		"\033[1;31m"
# define C_CLR		"\033[0m"
# define BUF_N		1024

typedef struct s_source
{
	int		cur;
	int		cur_x;
	int		cur_y;
	int		is_space;
	char	buffer[BUF_N];
}	t_source;

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_putstr(const char *msg);
ssize_t	read_stdin(char *buffer, size_t buffer_size);
void	print_grid(t_skyscraper *sky, int err_x, int err_y);
bool	validate_and_parse_grid(t_skyscraper *sky);

#endif
