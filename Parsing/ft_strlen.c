/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:42:27 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/19 20:42:27 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

//hello
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
    char str[] = "longcharacterslongcharacters";

    printf("The number of characters in this string: %lld\n", ft_strlen(str));

    return 0;
}*/
