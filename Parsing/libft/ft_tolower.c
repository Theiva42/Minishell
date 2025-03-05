/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:01:35 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/28 14:01:35 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_tolower(int ch)
{
	if ((ch >= 32 && ch <= 64) || (ch >= 91 && ch <= 127))
	{
		return (ch);
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		ch = ch + 32;
	}
	return (ch);
}
/*
#include <stdio.h>
int main(void)
{
    char upper = 'M';
    printf("%c\n", ft_tolower(upper));
    return 0;
}*/
