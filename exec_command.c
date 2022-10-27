/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:47:14 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/27 08:18:40 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec_command(char *argv, char **paths, char **envp)
{
    int     idx;
    char    *cmd;
    char    **cmd_flags;

    idx = 0;
    cmd_flags = ft_split(argv, ' ');
    while (paths[idx] != NULL)
    {
        cmd = ft_strjoin(paths[idx], cmd_flags[0]);
        execve(cmd, cmd_flags, envp);
        free(cmd);
        idx++;
    }
    m_free(paths);
    perror(cmd_flags[0]);
    m_free(cmd_flags);
    exit(1);
}
