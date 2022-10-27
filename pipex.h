/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:44:29 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/27 08:20:26 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdarg.h>
# include <sys/wait.h>

/* checkers */

void    check_valid(int n, char *error_msg);
void    check_args(int n);

/* create process */

void    create_process(char *argv[], char **paths, char *envp[]);

/* exec cmd */

void    exec_command(char *argv, char **paths, char **envp);

/* get path */

char    **get_path(char *envp[]);

/* utils */

char    **m_free(char **array);
void    close_fd(int fd_num, ...);


#endif