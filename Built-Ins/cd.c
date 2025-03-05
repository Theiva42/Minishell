/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:40:43 by thkumara          #+#    #+#             */
/*   Updated: 2024/12/27 17:57:06 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void ft_cd_minus(char *previous_path) 
{
    if (strlen(previous_path) == 0) {
        fprintf(stderr, "cd: previous directory not available\n");
        return;
    }
    
    // Change to the previous directory
    if (chdir(previous_path) == -1) {
        perror("cd");
    }
}

void	ft_cd(char *path)
{
	char	cwd[1024];
	int	cd;

	if (path == NULL || ft_strcmp(path, "~") == 0)
	{
		path = getenv("HOME");
		if (path == NULL)
			printf("cd: Home directory not set: %s\n", path);
		return;
	}
	getcwd(cwd, sizeof(cwd));
	printf ("Current directory: %s\n", cwd);
	cd = chdir(path);
	if (cd == -1)
			perror("cd");
	else
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf ("pwd: %s\n", cwd);
		else
			perror("getcwd");
	}
}

int	main(void)
{
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
}


