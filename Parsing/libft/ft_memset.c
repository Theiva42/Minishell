/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:30:26 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/20 16:30:26 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	u;
	char			*s;
	size_t			i;

	s = (char *)str;
	i = 0;
	u = c;
	while (i < n)
	{
		s[i] = u;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "this is a string";

    ft_memset(str, 'p', 5);
    printf("After memset: %s\n", str);
    
    memset(str, 'p', 5);
    printf("After memset: %s\n", str);
}*/
