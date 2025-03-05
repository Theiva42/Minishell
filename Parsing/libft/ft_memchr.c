/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:10:11 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/04 16:10:11 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*string;
	unsigned char		ch;

	string = (unsigned char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*string == ch)
		{
			return (string);
		}
		string++;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
   const char str[] = "this is a string";
   const char ch = 's';
   char *ret;

   ret = ft_memchr(str, ch, 2);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/
