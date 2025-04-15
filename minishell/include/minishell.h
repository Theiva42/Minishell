/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:58:54 by sbin-ham          #+#    #+#             */
/*   Updated: 2025/04/15 18:36:36 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include <stdio.h>					
# include <stdlib.h>				
# include <unistd.h>				
# include <sys/wait.h>				
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

extern char	**environ;

int is_builtin(char *cmd);
int execute_builtin(t_command *cmd);
void execute_commands(t_command *cmd_head);
int ft_unsetenv(char *var);
void    ft_env();
void    handle_export(char  *arg);
void    handle_newenv(char *key, char *value);
void    handle_unset(char   *var);
int     is_n_flag(char *str);
void    handle_echo(char **argv);
size_t	ft_strcpy(char *dst, const char *src);
int ft_strcmp(char *str1, char *str2);
size_t	ft_strcat(char *dst, char *src);
void    set_signals(void);

#endif
