/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:04:17 by thkumara          #+#    #+#             */
/*   Updated: 2024/12/27 15:10:51 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

extern char	**environ;

void	print_env_var(void)
{
	char	**env;

	env = environ;
	while (*env != NULL)
	{
		printf ("%s\n", *env);
		env++;
	}
}

int	main(void)
{
	print_env_var();
	return (0);
}
