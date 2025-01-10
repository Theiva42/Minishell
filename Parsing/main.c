/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:04:27 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/08 13:04:27 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i]) // unconditional jump if here, if line is not initialized
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*concatenate_lines(int i, char *line, char **av)
{
	int	k;

	k = 0;
	while (av[++k] != NULL)
	{
		line = ft_strcat(line, av[k]);
		if (av[k + 1] != NULL)
			line = ft_strcat(line, " ");
	}
	return (line);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	int		length;
	char	*cmd_line;
	char	*token;
	char	**command;
	t_oken	**cmd;

//concatenate cmd_line
//ft_split cmd_line
// 
	i = 1;
	while (av[i++] != NULL && i < ac)
		length += ft_strlen(av[i]) + 1;
	cmd_line = (char *)malloc(sizeof(char) * length);
	if (!cmd_line)
		return (-1);
	else
		cmd_line[0] = '\0';
	cmd_line = concatenate_lines(i, cmd_line, av);
	command = ft_split(cmd_line, '|');
	int c = 0;
	while (command[i] != NULL)
		c++;
	*cmd = malloc(sizeof(t_oken) * c); //check this
	if (!cmd)
		exit (1);
	free(cmd_line);
	i = 0;
	j = 0;
	k = 0;
	while (command[i] != NULL)
	{
		while (command[i][j] != ' ')
			j++;
		k += j;
		token = (char *)malloc(sizeof(char) * j);
		if (!token)
			exit (1);
		
		j++;
		k = 0;
	}
	i++;
}