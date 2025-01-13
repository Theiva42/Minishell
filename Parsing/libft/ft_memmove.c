/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:48:18 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/27 14:48:18 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = (char *)str1;
	s2 = (char *)str2;
	i = ((int)n) - 1;
	if (str1 > str2)
	{
		while (i >= 0)
		{
			s1[i] = s2[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(str1, str2, n);
	}
	return (str1);
}
/*
#include <string.h>
#include <stdio.h>
int main(void) 
{
    char str[] = "ClearSkies";
    ft_memmove(str + 5, str, 5);
    printf("%s\n", str);  

    return 0;
}*/
