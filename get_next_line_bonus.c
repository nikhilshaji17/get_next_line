/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:22:38 by nkunnath          #+#    #+#             */
/*   Updated: 2024/08/20 10:22:40 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*dup_till_nl(char *buffer)
{
	size_t	i;
	char	*result;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i = i + 1;
	if (buffer[i] == '\n')
		i += 1;
	result = (char *)malloc((sizeof(char) * i) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			result[i++] = '\n';
			break ;
		}
		result[i] = buffer[i];
		i += 1;
	}
	result[i] = '\0';
	return (result);
}

static void	read_into_buffer(int fd, char **buffer, char **curr_line)
{
	ssize_t	bytes_read;
	char	*temp_buffer;

	bytes_read = 1;
	while (!ft_strchr(*buffer, '\n'))
	{
		bytes_read = read(fd, *curr_line, BUFFER_SIZE);
		if (bytes_read == 0)
			return ;
		if (bytes_read == -1)
		{
			if (*buffer != NULL)
				free(*buffer);
			*buffer = NULL;
			return ;
		}
		(*curr_line)[bytes_read] = '\0';
		temp_buffer = ft_strjoin(*buffer, *curr_line);
		free(*buffer);
		*buffer = temp_buffer;
		if (*buffer == NULL)
			return ;
	}
}

static char	*ft_strdup_nnl(const char *s1)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	update_buffer(char **buffer)
{
	size_t	i;
	char	*temp;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	temp = ft_strdup_nnl(*buffer + i);
	if (temp == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	free(*buffer);
	*buffer = temp;
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*curr_line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_strdup("");
		if (buffer[fd] == NULL)
			return (NULL);
	}
	curr_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (curr_line == NULL)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	read_into_buffer(fd, &buffer[fd], &curr_line);
	free(curr_line);
	curr_line = NULL;
	if (buffer[fd] == NULL || buffer[fd][0] == '\0')
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	result = dup_till_nl(buffer[fd]);
	if (result == NULL)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	update_buffer(&buffer[fd]);
	return (result);
}
