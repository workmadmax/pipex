/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_simulator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:48:47 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/26 09:14:32 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pratice.h"

int main(int argc, char *argv[])
{
    int fd[2];
    
    if (pipe(fd) == -1)
    {
        return (1);
    }
    int pid = fork();
    if (pid == -1)
    {
        return (2);
    }
    if (pid == 0) // processo filho
    {
        char *argv[] = {"ping", "-c", "5", "google.com", NULL};
        char *envp[] = {NULL};
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execve("/sbin/ping", argv, envp);
    }
    int pid2 = fork();
    if (pid2 == -1)
    {
        return (3);
    }
    if (pid2 == 0) // processo filho
    {
        char *argv[] = {"grep", "statics", NULL};
        char *envp[] = {NULL};
        dup2(fd[0], STDERR_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve("/usr/bin/grep", argv, envp);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}
