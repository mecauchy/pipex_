/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:43:28 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/23 18:47:48 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <signal.h>

# define  EXIT_FAILURE 1
# define  EXIT_SUCCESS 0

# define  STDIN_FILENO 0
# define  STDOUT_FILENO 1

void	pipex(int ac, char **av, char **env);
void	first_cmd_exec(int *fd, char **av,char **env);
void	second_cmd_exec(int *fd, char **av, char **env);
char	*get_command_path(char *cmd, char **env);
char	*ft_is_path(char *path, char *cmd);
void	ft_error(char *str);
void	ft_perror(char *str);
void	free_split(char *str);

#endif