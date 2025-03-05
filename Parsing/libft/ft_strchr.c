/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:34:34 by rjoseph           #+#    #+#             */
/*   Updated: 2024/05/29 11:34:34 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	count;
	int	i;

	count = ft_strlen(str);
	i = 0;
	while (i <= count || *str != '\0')
	{
		if (*str == (char) c)
		{
			return ((char *)str);
		}
		if (i >= count)
		{
			return (NULL);
		}
		i++;
		str++;
	}
	return (NULL);
}
