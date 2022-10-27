/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:20:51 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/26 15:32:29 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    close_fd(int fd_num, ...)
{
    int     idx;
    va_list fds;
    
    va_start(fds, fd_num);
    idx = 0;
    while (idx < fd_num)
    {
        close(va_arg(fds, int));
        idx++;
    }
}

char    **m_free(char **array)
{
    int idx;

    idx = 0;
    while (array[idx])
    {
        free(array[idx]);
        idx++;
    }
    free(array);
    return (NULL);
}
