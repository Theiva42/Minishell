/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:02:56 by rjoseph           #+#    #+#             */
/*   Updated: 2024/06/12 16:02:56 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = ft_strlen(s);
	if (s == NULL)
	{
		return ;
	}
	write(fd, s, count);
}
/*
int main(void)
{
  char s[] = "This string";
  ft_putstr_fd(s, 1);
  
  return 0;
}*/
