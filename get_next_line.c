/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:35 by juanherr          #+#    #+#             */
/*   Updated: 2024/09/26 18:16:52 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	ssize_t		readbytes;
	size_t		i;
	char		*aux;
	char		*leftover;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{

		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
//		printf("%ld\n", BUFFER_SIZE);
		return (NULL);
	}
//	line = NULL;
	readbytes = read(fd, buffer, BUFFER_SIZE);
	if (readbytes < 0)
	{
		free (buffer);
		return (NULL);
	}
	while (readbytes > 0)
	{
		buffer[readbytes] = '\0';
		if (!line)
			line = ft_strdup("");
		aux = ft_strjoin(line, buffer);
		free(line);
		line = aux;
//		free(aux);
		if (ft_strchr(line, '\n'))
			break ;
		readbytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	i = 0;
	if (!line)
	{
		line = ft_strdup("");
	}
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		out = ft_substr(line, 0, i + 1);
		leftover = ft_strdup(line + i + 1);
		free (line);
		line = leftover;
		//free (leftover);
		return (out);
	}
	out = ft_strdup(line);
	free (line);
	line = NULL;
	if (ft_strlen(out) == 0)
	{
		free (out);
		out = NULL;
	}
	return (out);
}

/*
int	main(void)
{
	int	fd;
	char *line;
	size_t	i = 0;
	
	fd = open("texto.txt", O_RDONLY);
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