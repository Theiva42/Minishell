/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:06:23 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/16 12:21:50 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	numwrite(int len, int i, int n, char *num)
{
	while (len > i)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*num;

	i = 0;
	len = numlen(n);
	num = (char *)malloc(sizeof(char) * len + 1);
	if (num == NULL)
		return (0);
	if (n == -2147483648)
	{
		num[0] = '-';
		num[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		num[0] = '-';
		i = 1;
		n = -n;
	}
	numwrite(len, i, n, num);
	num[len] = '\0';
	return (num);
}
/*
#include <stdio.h>

int main(void)
{
	int i = -2147483648;
	ft_itoa(i);
	
	printf("%d", i);
}*/
