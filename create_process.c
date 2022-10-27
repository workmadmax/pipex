/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:54:27 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/27 08:19:41 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    create_process(char *argv[], char **paths, char *envp[])
{
    int     fd[2];
    pid_t   pid;

    check_valid(pipe(fd), "Piping error");
    pid = fork();
    check_valid(pid, "Forking creat error");
    if (pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        exec_command(argv[0], paths, envp);
    }
    dup2(fd[0], STDIN_FILENO);
    waitpid(pid, NULL, 1);
    close(fd[1]);
}
