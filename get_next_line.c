/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:53:26 by imeliani          #+#    #+#             */
/*   Updated: 2023/01/15 17:30:21 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*del(char *s1)
{
	int		i;
	int		j;
	char	*s2;

	j = -1;
	i = 0;
	if (!s1[0])
		return (free (s1), NULL);
	while (s1[++j] != '\n' && s1[j])
		;
	if (s1[j] == '\n')
		j++;
	s2 = calloc(sizeof(char), ft_strlen(s1) - j + 1);
	if (!s2)
		return (NULL);
	while (s1[j])
		s2[i++] = s1[j++];
	if (s1[j] == '\n')
		s2[i++] = '\n';
	s2[i] = 0;
	free (s1);
	return (s2);
}

char	*resline(char *str)
{
	int		i;
	char	*line;

	i = -1;
	if (!str[0])
		return (NULL);
	while (str[++i] != '\n' && str[i])
		;
	if (str[i] == '\n')
		i++;
	line = calloc(sizeof(char), (i + 1));
	i = -1;
	while (str[++i] != '\n' && str[i])
		line[i] = str[i];
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buffer;
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(stash[fd]), NULL);
		buffer[i] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	line = resline(stash[fd]);
	stash[fd] = del(stash[fd]);
	free (buffer);
	return (line);
}

// int main ()
// {
// 	int fd;
// 	int fd1;
// 	char *str;
// 	char *str1;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	fd1 = open("get_next_line.c", O_RDONLY);
// 	str = get_next_line(fd);
// 	str1 = get_next_line(fd1);
// 	while (str != NULL || str1 != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 		printf("%s", str1);
// 		free(str1);
// 		str1 = get_next_line(fd1);
// 	}
// }
