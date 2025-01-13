/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:14:53 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/28 12:14:53 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_toupper(int ch)
{
	if ((ch >= 32 && ch <= 96) || (ch >= 123 && ch <= 127))
	{
		return (ch);
	}
	if (ch >= 'a' && ch <= 'z')
	{
		ch = ch - 32;
	}
	return (ch);
}
/*
#include <stdio.h>
int main(void)
{
    char lower = '9';
    printf("%c\n", ft_toupper(lower));
    return 0;
}*/
