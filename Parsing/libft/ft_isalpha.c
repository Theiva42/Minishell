/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:00:08 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/17 16:00:08 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
    char x;
    char y;
    char z;

    x = 'x';
    printf("Result when uppercase alphabet is passed: %d\n", ft_isalpha(x));
    printf("ASCII #: %d\n", x);

    y = 'Y';
    printf("Result when uppercase alphabet is passed: %d\n", ft_isalpha(y));
    printf("ASCII #: %d\n", y);

    z = '\t';
    printf("Result when uppercase alphabet is passed: %d\n", ft_isalpha(z));
    printf("ASCII #: %d\n", z);

    return 0;
}*/
