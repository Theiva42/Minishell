/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:47:10 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/20 12:36:52 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check(char a, char const *set)
{
	int	i;

	i = ft_strlen(set);
	while (i >= 0)
	{
		if (set[i] == a)
		{
			return (1);
		}
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	t;

	i = 0;
	t = ft_strlen(s1);
	if (s1 == 0)
	{
		return (0);
	}
	while (s1[i] != '\0' && check(s1[i], set))
	{
		i++;
	}
	while (s1[t - 1] != '\0' && check(s1[t], set) && i < t)
	{
		t--;
	}
	str = ft_substr(s1, i, t - i + 1);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "   string   ";
    char str2[] = " ";

    char *trim = ft_strtrim(str1, str2);
    printf("%s", trim);
    return 0;
}*/
