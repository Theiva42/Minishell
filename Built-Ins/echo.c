/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:10:50 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/06 16:14:13 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i]) // unconditional jump if here, if line is not initialized
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

char	*concatenate_lines(int i, char *line, char **av)
{
	int	k;

	k = i;
	while (av[++k] != NULL)
	{
		line = ft_strcat(line, av[k]);
		if (av[k + 1] != NULL)
			line = ft_strcat(line, " ");
	}
	return (line);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		length;
	char	*line;

	if (ft_strcmp(av[1], "-n") == 0)
		i = 1;
	else
		i = 0;
	length = 0;
	j = i;
	while (av[j++] != NULL && j < ac)
		length += ft_strlen(av[j]) + 1;
	line = (char *)malloc(sizeof(char) * length);
	if (!line)
		return (-1);
	else
		line[0] = '\0';
	line = concatenate_lines(i, line, av);
	if (i == 1)
		printf("%s", line);
	else
		printf("%s\n", line);
	return (free(line), 0);
}
