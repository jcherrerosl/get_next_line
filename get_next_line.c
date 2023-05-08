/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:25:06 by juaherre          #+#    #+#             */
/*   Updated: 2023/05/08 16:27:24 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

void	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*get_overline(int fd)
{
	char	*buf;
	size_t	bytes;
	char	*joined;
	//char	*tmp_buf;

	joined = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			ft_free(joined);
		buf[bytes] = '\0';
		joined = ft_strjoin(joined, buf);
		if (!joined)
			return (NULL);
		if (check_n(buf, '\n') == 1 || bytes < BUFFER_SIZE)
			break ;
	}
	return (joined);
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
	// system("leaks -q a.out");
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