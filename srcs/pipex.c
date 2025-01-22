/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:43:13 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/22 13:45:08 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    first_cmd_exec(int *fd, char **av,char **env)
{
        int infile;
        
        infile = open(av[1], O_RDONLY);
        if (infile < 0)
            ft_perror("open infile error");
        dup2(infile, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(infile);
        execve(get_command_path(av[2], env), parse_args(av[2]), env);
        ft_perror("execve cmd1 error");
}

void    second_cmd_exec(int *fd, char **av, char **env)
{
        int outfile;
        
        outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile < 0)
            ft_perror("open outfile error");
        dup2(fd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(outfile);
        execve(get_command_path(av[3], env), parse_args(av[3]), env);
        ft_perror("execve cmd2 error");
}

void pipex(int ac, char **av, char **env)
{
    int fd[2];
    int pid1, pid2;

    if (ac < 5)
        ft_error("error : arguments");
    if (pipe(fd) == -1)
        ft_perror("pipe error");
    pid1 = fork();
    if (pid1 == -1)
        ft_perror("[PID1] ERROR");
    if (pid1 == 0)
        first_cmd_exec(fd, av, env);
    pid2 = fork();
    if (pid2 == -1)
        ft_perror("[PID2] ERROR");
    if (pid2 == 0)
        second_cmd_exec(fd, av, env);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

int main(int ac, char **av, char **env)
{
   // char *envp[] = {"PATH=/usr/bin", NULL};
    if (ac == 1)
        ft_error("error : arguments");
    pipex(ac, av, envp);
    return (0);
}