/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:26:14 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/12 14:26:14 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*storage;

	storage = (void *)malloc(count * size);
	if (storage == NULL)
	{
		return (NULL);
	}
	ft_bzero(storage, count * size);
	return (storage);
}
/*
#include <stdio.h>
int main(void) 
{
    int* a = (int*)ft_calloc(5, sizeof(int));
    
    printf("Array elements after calloc:\n");
    
    for (size_t i = 0; i < 5; i++) 
    {
        printf("%d ", a[i]);
    }

    free(a);
    
    return 0;
}*/
