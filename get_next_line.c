/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:25:06 by juaherre          #+#    #+#             */
/*   Updated: 2023/05/16 12:37:01 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	check_n(char *s, char c)
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

static void	*ft_free(char *s)
{
	free(s);
	return (NULL);
}
static char	*get_overline(int fd)
{
	char	*buf;
	size_t	bytes;
	char	*joined;

	joined = "";
	//joined = "";
	bytes = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		ft_free(buf);
	buf[0] = '\0';
	if (bytes < 0)
		ft_free(joined);
	while (bytes > 0 && check_n(buf, '\n') == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			joined = ft_strjoin(joined, buf);
		}
	}
	free(buf);
	return (joined);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*s;
	char		*line;
	size_t		i;

	if (!fd)
		return (NULL);
	s = get_overline(fd);
	if (ft_strlen(remainder) > 0)
		s = ft_strjoin(remainder, s);
	i = 0;
	remainder = ft_strchr(s, '\n') + 1;
	line = (char *)malloc(sizeof(char) * (ft_strlen(s) - ft_strlen(remainder)));
	if (ft_strlen(ft_strchr(s, '\n')) > 1)
	{
		while (i <= (ft_strlen(s) - ft_strlen(remainder)))
		{
			line[i] = s[i];
			i++;
		}
		return (line);
	}
	return (s);
}


/*
char	*get_next_line(int fd)
{
	char		*overline;
	char		*line;
	static char	*remainder;
	char		*s;
	int			fd;

	remainder = "";
	overline = get_overline(fd);
	line = ft_trimmer(overline);
	line = ft_strjoin(remainder, line);
}*/
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	while (get_next_line(fd))
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return (0);
}
