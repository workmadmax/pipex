/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:38:52 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/26 09:12:56 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pratice.h"

int main(void)
{
    printf("Main program startado..\n");
    
    char    *argv[] = {"palmeira", "palmeiras", NULL};
    char    *envp[] = { "some", "environment", NULL};
    if (execve("./test.exe", argv, envp) == 1)
        perror("Não foi possivel executar");
    printf("Endrick");
    return 1;
}