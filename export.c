/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:47:23 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/06 18:27:13 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

char	*ft_strchr(const char *str, int c)
{
	int	count;
	int	i;

	count = ft_strlen(str);
	i = 0;
	while (i <= count || *str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		if (i >= count)
		{
			return (NULL);
		}
		i++;
		str++;
	}
	return (NULL);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	insert_var(char *var, char *av)
{
	int		j;
	int		k;
	int		l;
	char	*num;
	char	*line;

	j = 0;
	l = 0;
	while (av[j] != '=')
		j++;
	j++;
	if (av[j] == '"')
		j++;
	while (av[j] != NULL)
	{
		j = k;
		while (ft_isdigit(av[k]) == 1)
			k++;
		if (av[k + 1] == NULL)
		{
			k = k - j;
			num = (char *)malloc((sizeof(char) * k) + 1);
			if (!num)
				exit(1);
			else
			{
				while (av[j] != NULL)
				{
					num[l] = av[j];
					l++;
					j++;
				}
				l = atoi(num);
			}
		}
		else if (av[k + 1] != NULL)
		{
			k = j;
			while (av[k] != NULL)
				k++;
			line = (char *)malloc((sizeof(char) * k) + 1);
			if (!line)
				exit (1);
			while (av[j] != NULL)
			{
				line[l] = av[j];
				l++;
				j++;
			}
			line[l] = '\0';
		}
	}
}
int	create_var(char **av, int i)
{
	int		j;
	char	*var;

	j = 0;
	while (av[i][j] != '=')
		j++;
	var = (char *)malloc((sizeof(char) * j) + 1);
	if (!var)
		exit(1);
	j = -1;
	while (av[i][++j] != '=')
		var[j] = av[i][j];
	var[j] = '\0';
	if (getenv(var) == NULL)
		return (1);
	else
		insert_var(var, av[i]);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	i;

	(void)ac;
	(void)envp;
	if (ft_strcmp(av[1], "export") != 0)
		return (1);
	else
		i = 2;
	while (av[i] != NULL)
	{
		if (ft_strchr(av[i], '=') == NULL)
			i++;
		else if (ft_strchr(av[i], '=') != NULL)
		{
			create_var(av, i);
			return (0);
		}
	}
	return (1);
}
