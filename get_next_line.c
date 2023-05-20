/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:25:06 by juaherre          #+#    #+#             */
/*   Updated: 2023/05/20 12:03:18 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*no_break(char *whole_line)
{
	if (ft_strlen(whole_line) == 0)
	{
		free(whole_line);
		return (NULL);
	}
	else
		return (whole_line);
}

static char	*get_overline(char **line)
{
	char	*remainder;
	char	*whole_line;
	int		i;

	i = 0;
	if (*line == NULL)
		return (NULL);
	while ((*line)[i] != '\n' && (*line)[i])
		i++;
	if ((*line)[i] == '\n')
	{
		whole_line = ft_substr(*line, 0, i + 1);
		remainder = ft_strdup(*line + (i + 1));
		free(*line);
		*line = remainder;
		return (whole_line);
	}
	whole_line = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (no_break(whole_line));
}

static char	*rnsend(int read_bytes, int fd, char *buffer, char **line)
{
	char	*temp;

	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		if (*line == NULL)
			*line = ft_strdup("");
		temp = ft_strjoin(*line, buffer);
		free(*line);
		*line = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (get_overline(line));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line = NULL;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(buffer);
		free(line);
		line = NULL;
		return (NULL);
	}
	return (rnsend(read_bytes, fd, buffer, &line));
}

/*#include <stdio.h>
int	main()
{
	char	*line = NULL;
	int		fd1;
	fd1 = open("text1.txt", O_RDONLY);
	//fd2 = open("text2.txt", O_RDONLY);
	//fd3 = open("text3.txt", O_RDONLY);
	if (fd1 == -1 )
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	system("leaks -q a.out");
	return (0);
}*/