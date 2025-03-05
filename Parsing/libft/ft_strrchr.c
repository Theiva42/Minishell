/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:41 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/30 15:00:41 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = ft_strlen(str);
	while (*str != '\0')
	{
		str++;
	}
	while (count >= 0)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		if (count <= 0)
		{
			return (NULL);
		}
		str--;
		count--;
	}
	return ((char *)str);
}
