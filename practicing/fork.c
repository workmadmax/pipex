/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:13:33 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/26 09:13:46 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pratice.h"

/* fork()
    A chamada de sistema fork é usada para criar um novo processo, o processo 'filho', que
    será executado simultaneamente ao processo 'pai'. não recebe parâmetros e retorna um inteiro.

    id == 0		->	child process
	id > 0		->	parent process
	id == -1	->	error with fork
*/
int main(void)
{
    int i;
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        //O código aqui dentro será executado no processo filho
        printf("pid do Filho: %d\n", getpid());
    }
    else
    {
        //O código neste trecho será executado no processo pai
        printf("pid do Pai: %d\n", getpid());
    }


    printf("Esta regiao sera executada por ambos processos\n");
    scanf("%d", &i);
    exit(0);
}

/*
int	main(int argc, char* argv[])
{
	int id = fork();
	if (id == 0)
	{
		printf("child\n");
	}
	else
	{
		fork();
	}
	printf( "Hello world %d\n", id);
	return (0);

}
*/