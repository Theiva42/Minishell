/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:05:00 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/10 16:05:00 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
	{
		str++;
	}
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
		{
			sign *= -1;
		}
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (sign * num);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *s = "  5823";
    printf("%d %d", ft_atoi(s), atoi(s));
    return (0);
}*/
