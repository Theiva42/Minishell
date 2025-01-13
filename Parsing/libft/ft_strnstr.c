/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:32:51 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/05 10:32:51 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)haystack;
	if (needle[i] == '\0')
	{
		return (t);
	}
	while (*t != '\0' && n >= ft_strlen(needle))
	{
		if (*t == *needle)
		{
			if ((ft_strncmp(needle, t, ft_strlen(needle)) == 0))
			{
				return (t);
			}
		}
		i++;
		n--;
		t++;
	}
	return (NULL);
}
/*
int main()
{
    char *haystack = "Eeny meeny miny moe!";
    char *needle = "moe";
    char *location;

    location = ft_strnstr(haystack,needle,21);
    if(location == NULL)
        printf("Can't find '%s' within '%s'\n",
            needle,
            haystack);
    else
        printf("Found '%s' within '%s'\n",
            needle,
            haystack);

    return(0);
}*/
