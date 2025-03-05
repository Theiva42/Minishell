/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:39:09 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/20 16:39:09 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[count] != '\0' && count < (size - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "marcooooo";
    char str2[] = "poloooooo";

    printf("The result is: %lld", ft_strlcpy(str1, str2, 5));

    return 0;
}*/
