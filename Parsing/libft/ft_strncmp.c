/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:47:14 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/02 11:47:14 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < (n - 1) && str1[i] == str2[i]
		&& str1[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "abc";
    char str2[] = "abc";
  
    int ret = ft_strncmp(str1, str2, 7); 

    if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}*/
