/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:37:29 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/23 16:37:29 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (char *)s;
	while (i < n)
	{
		st[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
int main(void)
{
    char str[] = "string";
    ft_bzero(str, 3);
    printf("%s", str);
    
    for (int i = 0; i < sizeof(str); i++) 
    {
        printf("%d ", str[i]);
    }
}*/
