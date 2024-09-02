/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:28:23 by nkunnath          #+#    #+#             */
/*   Updated: 2024/08/08 12:28:25 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i = i + 1;
	}
	if (temp[i] == (char)c)
		return (&temp[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i = i + 1;
	ptr = (char *)malloc((sizeof(char) * i) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i ++;
	}
	return (ptr);
}

static void	make_string(char *f_string, char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	l_one;
	int	l_two;	

	i = 0;
	j = 0;
	l_one = ft_strlen(s1);
	l_two = ft_strlen(s2);
	while (j < l_one)
	{
		f_string[i] = s1[j];
		i = i + 1;
		j = j + 1;
	}
	j = 0;
	while (j < l_two)
	{
		f_string[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	f_string[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_string;
	int		l_one;
	int		l_two;

	final_string = NULL;
	l_one = ft_strlen(s1);
	l_two = ft_strlen(s2);
	final_string = (char *)malloc((sizeof(char) * (l_one + l_two)) + 1);
	if (final_string == NULL)
		return (final_string);
	make_string(final_string, s1, s2);
	return (final_string);
}
