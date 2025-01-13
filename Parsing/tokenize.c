/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:55:43 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/13 16:52:44 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize(t_oken *cmd, char **command)
{
	char	*token;
	int		i;
	int		j;
	int		k;
	int		l;
	int		tkn;

	i = 0;
	j = 0;
	k = 0;
	tkn = 0;
	token = NULL;
	(void)cmd;
	while (command[i] != NULL)
	{
		while (command[i][j] != '\0')
		{
			while (command[i][j] == ' ')
				j++;
			while (command[i][j] != ' ')
				j++;
			if (k > 0)
				k = (j - k) + 1;
			else
				k = j + 1; //extra memory allocated if there are spaces in front of command on 2nd round
			token = (char *)malloc(sizeof(char) * k);
			if (!token)
				exit(1);
			else
			{
				l = 0;
				while (command[i][j - 1] != ' ' && command[i][j - 1] != '\0')
					j--;
				while (command[i][j] != ' ' && command[i][j] != '\0')
				{
					token[l] = command[i][j];
					l++;
					j++;
				}
				token[l] = '\0';
			}
			if (tkn == 0)
				cmd[i].command = ft_strdup(token);
			else if (tkn == 1 && ft_strchr("-", token[0]))
				cmd[i].flag = ft_strdup(token);
			else if (tkn == 1 && !ft_strchr("-", token[0]))
				cmd[i].argument = ft_strdup(token);
			else if (tkn > 1 && ft_strchr("><", token[0]))
				cmd[i].argument = ft_strdup(token);
			free(token);
			tkn++;
			j++;
		}
		i++;
		j = 0;
		k = 0;
		tkn = 0;
	}
}
