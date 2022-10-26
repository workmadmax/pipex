/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:03:24 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/26 09:14:46 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pratice.h"

int main(int argc, char *argv[])
{
    int pid = fork();
    
    if (pid == -1)
    {
        printf("Error ao criar o process");
        return (1);
    }
    if (pid == 0) //significa que to no process filho
    {
        sleep(4);
        printf("Finalizada a exec %d%d\n", getpid(), getppid());
        return (0);
    }
    
    int pid2 = fork();
    if (pid == -1)
    {
        printf("Error ao criar o processo '2'");
        return (2);
    }
    if (pid2 == 0)
    {
        sleep(1);
        printf("Finalizada a exec '2' %d%d\n", getpid(), getppid());
    }
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);
}