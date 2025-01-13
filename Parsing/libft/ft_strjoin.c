/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:52:52 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/13 14:52:52 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	int			l;
	int			m;

	l = 0;
	m = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
	{
		return (NULL);
	}
	while (s1[m] != '\0')
	{
		join[l++] = s1[m++];
	}
	m = 0;
	while (s2[m] != '\0')
	{
		join[l++] = s2[m++];
	}
	join[l] = '\0';
	return (join);
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "This is ";
    char str2[] = "a string";

    char *result = ft_strjoin(str1, str2);
    printf("%s", result);

    return 0;
}*/
