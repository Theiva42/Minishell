/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:16:16 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/09 19:27:34 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char *resolve_path(char *cmd) {
	char **paths;
	char *env_path;
	char *full;
	int i;

	i = 0;
	env_path = getenv("PATH");
	if (!env_path || ft_strchr(cmd, '/'))
		return ft_strdup(cmd);
	paths = ft_split(env_path, ':');
	while (paths[i]) 
	{
		full = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		ft_strcpy(full, paths[i]);
		ft_strcat(full, "/");
		ft_strcat(full, cmd);

		if (access(full, X_OK) == 0)
		{
			ft_free_split(paths);
			return full;
		}
		free(full);
		i++;
	}
	ft_free_split(paths);
	return NULL;
}

int	is_builtin(char	*cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset"));
}

int	execute_builtin(t_command *cmd)
{
	if (!cmd || !cmd->argv[0])
		return (0);
	if (!ft_strcmp(cmd->argv[0], "cd"))
	{
		if(!cmd->argv[1])
		{
			write(2, "cd: Argument missing\n", 21);
			return (1);
		}
		if (chdir(cmd->argv[1]) != 0)
		{
			perror("cd");
			return (1);
		}
		return (0);
	}
	else if (!ft_strcmp(cmd->argv[0], "pwd"))
	{
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)))
			printf("%s\n", cwd);
		else
			perror("pwd");
		return (0);
	}
	else if (!ft_strcmp(cmd->argv[0], "echo"))
		handle_echo(cmd->argv);
	else if (!ft_strcmp(cmd->argv[0], "export"))
		handle_export(cmd->argv[1]);
	else if (!ft_strcmp(cmd->argv[0], "unset"))
		handle_unset(cmd->argv[1]);
	else if (!ft_strcmp(cmd->argv[0], "env"))
		ft_env();
	else if (!ft_strcmp(cmd->argv[0], "exit"))
		exit (0);
	else
		return (0);
	return (0);
}
void	execute_commands(t_command *cmd_head)
{
	int fd_in;
	int fd;
	int pipefd[2];
	pid_t	pid;

	fd_in = 0;
	while (cmd_head)
	{
		if (is_builtin(cmd_head->argv[0]))
		{
			execute_builtin(cmd_head);
			cmd_head = cmd_head->next;
			continue;  
		}
		if (cmd_head->next && pipe(pipefd) == -1)
		{
			perror("pipe failed");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (cmd_head->infile)
			{
				int fd = open(cmd_head->infile, O_RDONLY);
				if (fd == -1)
				{
					perror("open infile failed");
					exit(EXIT_FAILURE);
				}
				dup2(fd, STDIN_FILENO);
				close(fd);
			}
			else if (fd_in != 0)
			{
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			if (cmd_head->outfile)
			{
				if (cmd_head->append_out)
					fd = open(cmd_head->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
				else
					fd = open(cmd_head->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (fd == -1)
				{
					perror("open outfile failed");
					exit(EXIT_FAILURE);
				}
				dup2(fd, STDOUT_FILENO);
				close(fd);
			}
			else if (cmd_head->next)
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
				close(pipefd[0]);
			}
			char *full_path = resolve_path(cmd_head->argv[0]);
			if (!full_path)
			{
				perror("Command not found");
				exit(127);
			}
			if (execve(full_path, cmd_head->argv, environ) == 1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		if (fd_in != 0)
			close(fd_in);
		if (cmd_head->next)
		{
			close(pipefd[1]);
			fd_in = pipefd[0];
		}
		cmd_head = cmd_head->next;
	}
	while (wait(NULL) > 0);
}
