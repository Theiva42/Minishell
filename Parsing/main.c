/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:04:27 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/17 21:18:19 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*concatenate_lines(int ac, char **av)
{
	int i;
	int length;
	char *line;

	i = 0;
	length = 0;
	while (av[i++] != NULL && i < ac)
		length += ft_strlen(av[i]) + 1;
	line = (char *)malloc(sizeof(char) * length);
	if (!line)
		exit (-1); //exit
	else
		line[0] = '\0';
	i = 0;
	while (av[++i] != NULL)
	{
		line = ft_strcat(line, av[i]);
		if (av[i + 1] != NULL)
			line = ft_strcat(line, " ");
	}
	return (line);
}

void	free_lines(char *cmd_line, char **command)
{
	int	i;

	i = 0;
	free(cmd_line);
	while(command[i] != NULL)
	{
		free(command[i]);
		i++;
	}
	free(command);
}

int	minishell(int ac, char **av)
{
	int		c;
	char	*cmd_line;
	char	**command;
	t_oken	*cmd;

	cmd = NULL;
	c = 0;
	cmd_line = concatenate_lines(ac, av);
	command = ft_split(cmd_line, '|');
	while (command[c] != NULL)
		c++;
	initialize_struct(&cmd, c);
	tokenize(cmd, command);
	free_lines(cmd_line, command);
	return (0);
}

int	main(int ac, char **av)
{
	//user runs make first then running minishell has to launch a prompt
	int i = minishell(ac, av);
	return (i);
}
