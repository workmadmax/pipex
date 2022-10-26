/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:13:54 by mdouglas          #+#    #+#             */
/*   Updated: 2022/10/26 09:13:58 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pratice.h"

int	main(int argc, char* argv[])
{
	int fd[2];
	
	if (pipe(fd) == -1)
	{
		printf("pipe error\n");
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("y: %d\n", y);
	}
	
	return (0);
}