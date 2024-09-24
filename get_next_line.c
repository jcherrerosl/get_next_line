/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:35 by juanherr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/24 15:35:02 by juanherr         ###   ########.fr       */
=======
/*   Updated: 2024/09/24 16:29:31 by juanherr         ###   ########.fr       */
>>>>>>> cb26a45 (a)
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
<<<<<<< HEAD
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
=======
	line = "";
	readbytes = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	ft_putstr_fd(line, 1);
	return (buffer);
>>>>>>> cb26a45 (a)
}

int	main(void)
{
	int	fd;
<<<<<<< HEAD

	fd = open("texto.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
=======
	static char	*line = NULL;

	fd = open("texto.txt", O_RDONLY);
	get_next_line(fd);
	//while (get_next_line(fd))
	//{
	//	get_next_line(fd);
	//}
	return (0);
}
>>>>>>> cb26a45 (a)
