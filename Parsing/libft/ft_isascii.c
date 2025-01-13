/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:42:56 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/18 13:42:56 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
    char d;
    char e;
    char f;
    char g;

    char c = 's';
    printf("The return value is: %d\n", ft_isascii(c));

    d = 'G';
    printf("The return value is: %d\n", ft_isascii(d));

    e = '3';
    printf("The return value is: %d\n", ft_isascii(e));

    f = '\b';
    printf("The return value is: %d\n", ft_isascii(f));

    g = 200;
    printf("The return value is: %d", ft_isascii(g));
    return 0;
}*/
