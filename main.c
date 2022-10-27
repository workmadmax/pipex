/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:47:00 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/27 08:13:42 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int     filein;
    int     fileout;
    int     count;
    char    **paths;
    
    check_args(argc);
    filein = open(argv[1], O_RDONLY);
    check_valid(filein, argv[1]);
    fileout = open(argv[argc - 1], O_CREAT, O_WRONLY, O_TRUNC, 0777);
    check_valid(fileout, argv[argc - 1]);
    dup2(filein, STDIN_FILENO);
    dup2(fileout, STDOUT_FILENO);
    paths = get_path(envp);
    count = 2;
    while (count < argc - 2)
    {
        create_process(argv + count, paths, envp);
        count++;
    }
    exec_command(argv[argc - 2], paths, envp);
    close_fd(2, fileout, filein);
    return (0);
}