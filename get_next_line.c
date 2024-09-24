/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:35 by juanherr          #+#    #+#             */
/*   Updated: 2024/09/24 15:35:02 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	size_t		readbytes;
	size_t		i;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = NULL;
	readbytes = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
	{
		line = &buffer[i];
		i++;
	}
	ft_putstr_fd(line, 1);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}