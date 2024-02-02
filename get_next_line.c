/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:40:07 by hcharra           #+#    #+#             */
/*   Updated: 2023/12/19 11:40:12 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*freeandreturn(char *buffer, char *container)
{
	free(buffer);
	free(container);
	return (NULL);
}

static char	*read_bytes(int fd, char *container)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(container, '\n') && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (freeandreturn(buffer, container));
		buffer[bytes] = '\0';
		container = ft_strjoin(container, buffer);
	}
	free(buffer);
	if (container[0] == '\0')
	{
		free(container);
		return (NULL);
	}
	return (container);
}

static char	*get_line_(char *container)
{
	char	*line;
	int		i;

	i = 0;
	if (!container)
		return (NULL);
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		line[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*rest_of_line(char *container)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!container)
	{
		free(container);
		return (NULL);
	}
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	rest = malloc((ft_strlen(container) - i) + 1);
	if (!rest)
		return (NULL);
	while (container[i])
	{
		rest[j++] = container[i++];
	}
	rest[j] = '\0';
	free(container);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	container = read_bytes(fd, container);
	if (!container)
		return (NULL);
	line = get_line_(container);
	container = rest_of_line(container);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	fd = open("text.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

//     line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// }

// int main()
// {
// 	//int i = open("test.txt", O_CREAT, O_RDWR);
// 	int i = 0;
// 	char *line = get_next_line(i);
// 	printf("%s", line);
// 	while(line)
// 	{
// 		line = get_next_line(i);
// 		printf("%s", line);
// 		//i++
// 	}
// 	free(line);
// }