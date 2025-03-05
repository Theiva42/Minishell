/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:09:09 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/19 17:58:52 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char	*strim(char *str, char de)
{
	size_t	i;
	size_t	t;

	if (str == NULL)
	{
		return (NULL);
	}
	t = ft_strlen(str);
	i = 0;
	while (str[i] != '\0' && str[i] == de)
	{
		i++;
	}
	while (t > 0 && str[t - 1] == de)
	{
		t--;
	}
	str = ft_substr(str, i, t - i);
	return (str);
}

static int	numwords(char *str, char delim)
{
	int	count;

	count = 1;
	if (ft_strlen(str) == 0)
		return (0);
	while (*str != '\0')
	{
		if (*str == delim)
		{
			count++;
			while (*str == delim)
				str++;
		}
		str++;
	}
	return (count);
}

static int	numdelim(char *trim, char de)
{
	int	count;

	count = 0;
	while (*trim == de)
	{
		count++;
		trim++;
	}
	return (count);
}

static char	**wordsep(char *trim, char de, int wc, int count)
{
	char	**res;
	char	*start;

	res = (char **)malloc((wc + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (count < wc)
	{
		start = trim;
		while (*trim != de && *trim != '\0')
			trim++;
		res[count] = (char *)malloc((trim - start) + 1);
		if (res[count] == NULL)
		{
			while (count > 0)
				free(res[--count]);
			free(res);
			return (NULL);
		}
		ft_strlcpy(res[count], start, (trim - start) + 1);
		count++;
		trim += numdelim(trim, de);
	}
	res[count] = NULL;
	return (res);
}

char	**ft_split(char const *str, char de)
{
	char	*trim;
	char	**res;
	int		wc;
	int		count;

	count = 0;
	trim = strim((char *)str, de);
	if (trim == NULL)
		return (NULL);
	wc = numwords((char *)trim, de);
	res = wordsep(trim, de, wc, count);
	free(trim);
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
/*
#include <stdio.h>
int main(void) 
{
    char **result;
    int i;

	i = 0;
    const char *str = "hello!zzzzzz";
    char de = 'z';

    result = ft_split(str, de);

    while (result[i] != NULL) {
        printf("Word %d: %s\n", i + 1, result[i]);
        i++;
    }

    return 0;
}*/
