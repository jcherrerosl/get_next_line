/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:35 by juanherr          #+#    #+#             */
/*   Updated: 2024/09/25 16:56:05 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	size_t		readbytes;
	size_t		i;
	char		*aux;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER_SIZE);
	if (readbytes <= 0)
	{
		free (buffer);
		return (line);
	}
	while (readbytes > 0)
	{
		buffer[readbytes] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(line, buffer);
			free (line);
			line = aux;
		}
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}


int	main(void)
{
	int			fd;
	
	fd = open("texto.txt", O_RDONLY);
	ft_putstr_fd(get_next_line(fd), 1);
	close(fd);
	return (0);
}
