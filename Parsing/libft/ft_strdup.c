/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:00:40 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/20 12:21:34 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	str = (char *)malloc((count * sizeof(char)) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "string";
	char* target = ft_strdup(src); 

	printf("%s", target);
	return 0;
}*/
