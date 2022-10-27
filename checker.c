/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:10:33 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/27 08:20:07 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    check_valid(int n, char *error_msg)
{
    if (n == -1)
    {
        perror(error_msg);
        exit(2);
    }
}

void    check_args(int n)
{
    if (n < 5)
    {
        printf("Error nos argumentos passados\n");
        exit(1);
    }
}