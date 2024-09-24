/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:15 by juanherr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/24 15:24:42 by juanherr         ###   ########.fr       */
=======
/*   Updated: 2024/09/24 16:25:39 by juanherr         ###   ########.fr       */
>>>>>>> cb26a45 (a)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
<<<<<<< HEAD
#  define BUFFER_SIZE 10
=======
#  define BUFFER_SIZE 10000
>>>>>>> cb26a45 (a)
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
<<<<<<< HEAD
=======
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putendl_fd(char *s, int fd);
>>>>>>> cb26a45 (a)

#endif