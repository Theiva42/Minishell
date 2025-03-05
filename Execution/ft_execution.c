/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:22 by thkumara          #+#    #+#             */
/*   Updated: 2025/01/22 17:20:46 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_execution(t_token **cmd)
{
	int	i;
	char *args;
	char *path;

	i = 0;
	while (cmd[i].argument)
	{
		args[i] = cmd[i].argument;
		i++;
	}
	args[i] = '\0';
	i = 0;
		char *path = "new";
	char	*previous_path;
	char	cwd[1024];
	
	if (getcwd(cwd, sizeof(cwd)) != NULL) 
        	strncpy(previous_path, cwd, 1024); 
   	else 
   	{
       		perror("getcwd");
        	return;
    	}
		
	if (path[0] != NULL && strcmp(path[0], "cd") == 0) {
            if (path[1] != NULL && strcmp(path[1], "-") == 0) {
                ft_cd_minus(previous_path); // Handle 'cd -'
            } else {
                ft_cd(path[1]); // Handle 'cd <path>'
            }
            
	return (0);

	pid = fork();
}
