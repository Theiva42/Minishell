/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:55:43 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/17 17:24:28 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	tokenize(t_oken *cmd, char **command)
// {
// 	char	*token;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		l;
// 	int		tkn;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	tkn = 0;
// 	token = NULL;
// 	(void)cmd;
// 	while (command[i] != NULL)
// 	{
// 		while (command[i][j] != '\0')
// 		{
// 			while (command[i][j] == ' ')
// 				j++;
// 			while (command[i][j] != ' ')
// 				j++;
// 			if (k > 0)
// 				k = (j - k) + 1;
// 			else
// 				k = j + 1;
					//extra memory allocated if there are spaces in front of command on 2nd round
// 			token = (char *)malloc(sizeof(char) * k);
// 			if (!token)
// 				exit(1);
// 			else
// 			{
// 				l = 0;
// 				while (command[i][j - 1] != ' ' && command[i][j - 1] != '\0')
// 					j--;
// 				while (command[i][j] != ' ' && command[i][j] != '\0')
// 				{
// 					token[l] = command[i][j];
// 					l++;
// 					j++;
// 				}
// 				token[l] = '\0';
// 			}
// 			if (tkn == 0)
// 				cmd[i].command = ft_strdup(token);
// 			else if (tkn == 1 && ft_strchr("-", token[0]))
// 				cmd[i].flag = ft_strdup(token);
// 			else if (tkn == 1 && !ft_strchr("-", token[0]))
// 				cmd[i].argument = ft_strdup(token);
// 			else if (tkn > 1 && ft_strchr("><", token[0]))
// 				cmd[i].argument = ft_strdup(token);
// 			free(token);
// 			tkn++;
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 		k = 0;
// 		tkn = 0;
// 	}
// }

void	sort_token(t_oken *cmd, char *token, int *i, int tkn)
{
	if (tkn == 0)
		cmd[*i].command = ft_strdup(token);
	else if (tkn == 1 && ft_strchr("-", token[0]))
		cmd[*i].flag = ft_strdup(token);
	else if (tkn == 1 && !ft_strchr("-", token[0]))
		cmd[*i].argument = ft_strdup(token);
	else if (tkn > 1 && ft_strchr("><", token[0]))
		cmd[*i].redirect = ft_strdup(token);
}

void	create_token(char **token, char *command, int *j)
{
	int	l;

	l = 0;
	while (command[*j - 1] != ' ' && command[*j - 1] != '\0')
		(*j)--;
	while (command[*j] != ' ' && command[*j] != '\0')
	{
		(*token)[l] = command[*j];
		l++;
		(*j)++;
	}
	(*token)[l] = '\0';
}

void	allocate_memory(char **token, int k)
{
	*token = (char *)malloc(sizeof(char) * k);
	if (!(*token))
		exit(1);
}

void	tokenize_command(t_oken *cmd, char *command, int i)
{
	char	*token;
	int		j;
	int		k;
	int		tkn;

	j = 0;
	k = 0;
	tkn = 0;
	while (command[j] != '\0')
	{
		while (command[j] == ' ')
			j++;
		while (command[j] != ' ' && command[j] != '\0')
			j++;
		if (k != 0)
			k = (j - k) + 1;
		else
			k = j + 1;
		allocate_memory(&token, k);
		create_token(&token, command, &j);
		sort_token(cmd, token, &i, tkn);
		free(token);
		tkn++;
		j++;
	}
}

void	tokenize(t_oken *cmd, char **command)
{
	int	i;

	i = 0;
	while (command[i] != NULL)
	{
		tokenize_command(cmd, command[i], i);
		i++;
	}
}
