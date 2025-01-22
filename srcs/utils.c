/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:43:18 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/22 16:30:23 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_command_path(char *cmd, char **env)
{
	int		i;
	char	*get_path;
	char	*full_path;
	char	**path;
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
		ft_error();
	path = ft_split(get_path, ":");
	i = 0;
	while (path[i])
	{
		full_path = malloc(sizeof(char *) * (ft_strlen(path) + ft_strlen(cmd) + 2));
		if (!full_path)
			ft_error();
		if (access((full_path[i]), X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
}