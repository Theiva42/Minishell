/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:15:00 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/19 21:52:02 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (s[count] != '\0')
	{
		str[count] = (*f)(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
/*
#include <stdio.h>
char testfx(unsigned int i, char c)
{
    return c + i;
}
int main(void)
{
    char *str = "This string";
    char *result = ft_strmapi(str, testfx);

	printf("%s\n", result);
    free(result);
   
    return 0;
}*/