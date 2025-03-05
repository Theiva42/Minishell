/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:17:04 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/27 16:17:04 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dlen;
	size_t	slen;

	count = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size == 0)
	{
		return (size + slen);
	}
	while ((src[count] != '\0') && (count + dlen < size - 1))
	{
		dst[dlen + count] = src[count];
		count++;
	}
	dst[dlen + count] = '\0';
	if (dlen < size)
	{
		return (dlen + slen);
	}
	return (size + slen);
}
/*
#include <stdio.h>
int main() 
{
    char dst[25] = "This is ";
    const char *src = "a string!";
    size_t dstsize = sizeof(dst);

    size_t result = ft_strlcat(dst, src, dstsize);

    printf("Result: %zu\n", result);
    printf("Destination buffer: %s\n", dst);

    return 0;
}*/
