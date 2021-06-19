/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidus <fidus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:56:02 by fidus             #+#    #+#             */
/*   Updated: 2021/06/16 17:43:24 by fidus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	decriptage(int signal_code)
{
	static unsigned char	c;
	static char				i;

	c += (SIGUSR1 == signal_code) << i;
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		ft_putstr_fd("error\nThe number of arguments is not correct\n", 2);
		exit(1);
	}
	if (av[0])
	{
		ft_putstr_fd("server pid :", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd("\n", 1);
		signal(SIGUSR1, decriptage);
		signal(SIGUSR2, decriptage);
		while (1)
			pause();
	}
	return (0);
}
