/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:35 by juanherr          #+#    #+#             */
/*   Updated: 2024/09/27 18:39:29 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static char	*check_end(char *out)
{
	if (ft_strlen(out) == 0)
	{
		free(out);
		return (NULL);
	}
	else
		return (out);
}

static char	*line_leftover(char **line)
{
	char	*leftover;
	char	*out;
	int		i;

	i = 0;
	if (*line == NULL)
		return (NULL);
	while ((*line)[i] != '\n' && (*line)[i])
		i++;
	if ((*line)[i] == '\n')
	{
		out = ft_substr(*line, 0, i + 1);
		leftover = ft_strdup(*line + (i + 1));
		if (!out || !leftover)
			return (free_and_null(line));
		free(*line);
		*line = leftover;
		return (out);
	}
	out = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (check_end(out));
}

static char	*reading(int read_bytes, int fd, char *buffer, char **line)
{
	char	*aux;

	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		if (*line == NULL)
			*line = ft_strdup("");
		aux = ft_strjoin(*line, buffer);
		free(*line);
		*line = aux;
		if (ft_strchr(buffer, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line_leftover(line));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
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
	return (reading(read_bytes, fd, buffer, &line));
}

/*
int	main(void)
{
	int	fd;
	char *line;
	size_t	i = 0;
	
	fd = open("1char.txt", O_RDONLY);
	line = get_next_line(fd);
	
	//ft_putstr_fd(line, 1);
	
	//while (i < 3)
	//{
	//	printf("%s", line);
	//	i++;
	//	line = get_next_line(fd);
	//}
	
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/