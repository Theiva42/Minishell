/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:36 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/18 17:28:36 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
    char b;
    char g;

    x = 'S';
    printf("The return value is: %d\n", ft_isprint(x));

    b = '.';
    printf("The return value is: %d\n", ft_isprint(b));

    g = '\t';
    printf("The return value is: %d\n", ft_isprint(g));

    return 0;
}*/
