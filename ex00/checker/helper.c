/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/15 13:19:18 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/15 17:30:18 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		++end;
	return (end - s);
}

void	ft_putchar(char c)
{
	write(STDERR_FILENO, &c, 1);
}

int	ft_putstr(const char *msg)
{
	write (STDERR_FILENO, msg, ft_strlen(msg));
	return (1);
}

ssize_t	read_stdin(char *buffer, size_t buffer_size)
{
	ssize_t	len;

	len = read(STDIN_FILENO, buffer, buffer_size - 1);
	if (len == -1)
		return (len);
	buffer[len] = '\0';
	return (len);
}
