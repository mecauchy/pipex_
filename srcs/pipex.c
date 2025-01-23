/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:43:13 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/23 13:52:47 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    first_cmd_exec(int *fd, char **av,char **env)
{
        int     infile;
        char    **cmd_args;
        char    *cmd_path;
        
        infile = open(av[1], O_RDONLY);
        if (infile < 0)
            perror("open infile error");
        cmd_args = ft_split(av[2], ' ');
        if (!cmd_args)
            perror("cmd1 split error");
        cmd_path = get_command_path(av[2], env);
        if (!cmd_path)
        {
            free(cmd_args);
            free(cmd_path);
            perror("cmd1 get_command_path error");
            exit(127);
        }
        dup2(infile, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(infile);
        execve(cmd_path, cmd_args, env);
        free(cmd_args);
        perror("execve cmd1 error");
}

void    second_cmd_exec(int *fd, char **av, char **env)
{
        int     outfile;
        char    **cmd_args;
        char    *cmd_path;
        
        outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile < 0)
            perror("open outfile error");
        cmd_args = ft_split(av[3], ' ');
        if (!cmd_args)
            perror("cmd2 split error");
        cmd_path = get_command_path(av[3], env);
        if (!cmd_path)
        {
            free(cmd_args);
            free(cmd_path);
            perror("cmd1 get_command_path error");
            exit(127);
        }
        dup2(fd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(outfile);
        execve(cmd_path, cmd_args, env);
        free(cmd_args);
        perror("execve cmd2 error");
}

void pipex(int ac, char **av, char **env)
{
    int fd[2];
    int pid1;
    int pid2;

    if (ac < 5)
        ft_putendl_fd("error : arguments", 2);
    if (pipe(fd) == -1)
        perror("pipe error");
    pid1 = fork();
    if (pid1 == -1)
        perror("[PID1] ERROR");
    if (pid1 == 0)
        first_cmd_exec(fd, av, env);
    pid2 = fork();
    if (pid2 == -1)
        perror("[PID2] ERROR");
    if (pid2 == 0)
        second_cmd_exec(fd, av, env);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

int main(int ac, char **av, char **env)
{
    if (ac == 1)
        ft_putendl_fd("error : arguments", 2);
    pipex(ac, av, env);
    return (0);
}
