/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:55:52 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/18 12:55:52 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
    int x;
    char y;

    x = '2';
    printf("The return value is: %d\n", ft_isdigit(x));

    y = 'A';
    printf("The return value is %d\n", ft_isdigit(y));

    return 0;

}*/
