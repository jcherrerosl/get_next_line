/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:25:06 by juaherre          #+#    #+#             */
/*   Updated: 2023/05/07 21:47:39 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_free(char *s)
{
	
}

char	*get_overline(int fd)
{
	char	*buf;
	size_t	bytes;
	char	*joined;
	char	*tmp_buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[bytes] = '\0';
	while (check_n(buf, '\n') == 0)
	{
		tmp_buf = ft_strdup(buf);
		if (!tmp_buf)
		{
			free(buf);
			return (NULL);
		}
			joined = ft_strjoin(tmp_buf, buf);
			free(buf);
			return (joined);
		}
	}
	return (buf);
}
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	s = get_overline(fd);
	printf("%s\n", s);
	close(fd);
	return (0);
}

/*char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*remainder;
	int			bytes;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buf);
		free(line);
		return (NULL);
	}
	else
	{
		buf[bytes] = '\0';
		if (remainder)
		{
			line = ft_strjoin(remainder, buf);
			free(buf);
			free(remainder);
			remainder = NULL;
		}
		else
			line = buf;
		while (line[bytes - 1] == '\n')
			line[--bytes] = '\0';
		remainder = ft_strjoin(line, buf + bytes);
		free(buf);
	}
	return (line);
}
*/