/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:56:53 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/14 04:51:59 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_cpy(char *line, char *line_save)
{
	int		i;

	i = 0;
	while (line_save[i] != '\n' && line_save[i] != '\0')
	{	
		line[i] = line_save[i];
		i++;
	}
	if (line_save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_remainder(char *line_save)
{
	int		i;
	int		j;
	int		line_save_len;
	char	*remainder;

	i = 0;
	j = 0;
	line_save_len = ft_strlen(line_save);
	while (line_save[i] != '\n' && line_save[i] != '\0')
		i++;
	if (line_save[i] == '\0')
	{
		free(line_save);
		return (NULL);
	}
	remainder = (char *)malloc((line_save_len - i + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	i++;
	while (line_save[i])
		remainder[j++] = line_save[i++];
	remainder[j] = '\0';
	free(line_save);
	return (remainder);
}

char	*ft_line(char *line_save)
{
	int		i;
	char	*line;

	i = 0;
	if (!line_save)
		return (NULL);
	while (line_save[i] != '\n' && line_save[i] != '\0')
		i++;
	if (line_save[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	if (line_save[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line_cpy(line, line_save));
}

char	*ft_read(int fd, char *line_save)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(line_save, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line_save = ft_strjoin(line_save, buffer);
	}
	free(buffer);
	return (line_save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_save[256];

	line = NULL;
	if (fd < 0 || fd > 256)
		return (NULL);
	line_save[fd] = ft_read(fd, line_save[fd]);
	if (!line_save[fd])
		return (NULL);
	line = ft_line(line_save[fd]);
	line_save[fd] = ft_remainder(line_save[fd]);
	return (line);
}
