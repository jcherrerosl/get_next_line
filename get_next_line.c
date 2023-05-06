/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:25:06 by juaherre          #+#    #+#             */
/*   Updated: 2023/05/06 21:58:54 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}

static char	*ft_read_overline(int fd, char *s)
{
	char	*overline;
	int		i;

	i = 0;
	overline = NULL;
	while (i < BUFFER_SIZE)
	{
		if (overline[i] != '\n')
			overline = ft_strjoin(overline, s);
		i++;
	}
	return (overline);
}

char	*ft_trimmer(char *s)
{
	int		i;

}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*remainder;
	int			bytes;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buf);
		ft_free(line);
	}
}
