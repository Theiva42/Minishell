/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:46:09 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/13 12:46:09 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	t;

	t = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (start < ft_strlen(s) && (t < len && s[start + t] != '\0'))
	{
		t++;
	}
	sub = malloc(sizeof(char) * (t + 1));
	if (sub == NULL)
	{
		free(sub);
		return (0);
	}
	while (start < ft_strlen(s) && i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
//code too long - can't account for < 0
int main(void)
{
    char str[] = "this is a string";
    char *subs = ft_substr(str, 5, 7);

    printf("%s", subs);

    return 0;
}*/
