/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:11:25 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/18 13:11:25 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
#include <stdio.h>
int main(void)
{
    char x;
    char y;
    char z;
    char c;

    x = 'A';
    printf("The return value is: %d\n", ft_isalnum(x));

    y = '4';
    printf("The return value is: %d\n", ft_isalnum(y));

    z = '&';
    printf("The return value is: %d\n", ft_isalnum(z));

    c = 'f';
    printf("The return value is: %d", ft_isalnum(c));

    return 0;
}*/
