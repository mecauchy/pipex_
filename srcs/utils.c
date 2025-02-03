/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:43:18 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/03 10:57:36 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_is_path(char *path, char *cmd)
{
	char	*try;
	int		i;
	int		j;

	i = 0;
	j = 0;
	try = malloc(sizeof(char *) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!try)
		return (NULL);
	while (path[i])
	{
		try[j] = path[i];
		i++;
		j++;
	}
	try[j] = '/';
	i = 0;
	while (cmd[i])
	{
		try[j] = cmd[i];
		j++;
		i++;
	}
	try[j] = '\0';
	return (try);
}

char	**get_path(char **env)
{
	char	*get_path;
	char	**path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			get_path = env[i] + 5;
			break ;
		}
		i++;
	}
	if (!get_path)
		ft_error("Error: path not found");
	path = ft_split(get_path, ':');
	if (!path)
		exit(EXIT_FAILURE);
	return (path);
}

char	*get_command_path(char *cmd, char **env)
{
	char	**path;
	char	**cut_cmd;
	char	*cmd_path;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK | F_OK) == 0)
			return (ft_strdup(cmd));
	}
	path = get_path(env);
	if (!path)
		return (NULL);
	cut_cmd = ft_split(cmd, ' ');
	if (!cut_cmd)
	{
		free_split(path);
		return (NULL);
	}
	cmd_path = try_path(path, cut_cmd[0]);
	free_split(path);
	free_split(cut_cmd);
	return (cmd_path);
}

char	*try_path(char **path, char *cut_cmd)
{
	int		i;
	char	*full_path;

	i = 0;
	while (path[i])
	{
		full_path = join_path(path[i], cut_cmd);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*join_path(char *path, char *cut_cmd)
{
	char	*add_slash;
	char	*full_path;

	add_slash = ft_strjoin(path, "/");
	if (!add_slash)
		return (NULL);
	full_path = ft_strjoin(add_slash, cut_cmd);
	free(add_slash);
	return (full_path);
}
