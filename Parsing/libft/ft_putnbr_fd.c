/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:11:31 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/13 16:11:31 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd(num % 10 + '0', fd);
}
/*
int main(void)
{
	int n = -123;
	ft_putnbr_fd(n, 1);

	return 0;
}*/
