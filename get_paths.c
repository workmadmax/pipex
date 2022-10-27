/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:26:40 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/27 08:21:39 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_path(char *env[])
{
    int     idx;
    char    *str;
    char    **out;

    idx = 0;
    while (!(ft_strnstr(env[idx], "PATH=", 5)))
        idx++;
    str = ft_strtrim(env[idx], "PATH=");
    out = ft_split(str, ':');
    free(str);
    idx = 0;
    while (out[idx])
    {
        str = ft_strjoin(out[idx], "/");
        free (out[idx]);
        out[idx] = str;
        idx++;
    }
    return (out);
}
