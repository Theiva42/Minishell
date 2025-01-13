/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:09:48 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/13 15:49:43 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct	s_token
{
	char	*command;
	char	*flag;
	char	*argument;
	char	*redirect;
}	t_oken;

char	*ft_strcat(char *dest, const char *src);
void 	initialize_struct(t_oken **cmd, int c);
void    tokenize(t_oken *cmd, char **command);
int		minishell(int ac, char **av);

#endif
