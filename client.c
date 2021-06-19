/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidus <fidus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:56:06 by fidus             #+#    #+#             */
/*   Updated: 2021/06/16 18:02:20 by fidus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\n Please Check Your Input And/Or Your Pid\n", 2);
	if (i == 2)
		ft_putstr_fd("error\nThis process does not exist\n", 2);
	exit(EXIT_FAILURE);
}

void	init(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	ret;

	init(&i, &j);
	if (ac != 3)
		ft_error(1);
	if (!is_digit(av[1]))
		ft_error(1);
	while (av[2][i])
	{
		j = 0;
		while (j < 8 && (usleep(150) || 1))
		{
			if ((av[2][i] >> j) & 1)
				ret = kill(ft_atoi(av[1]), SIGUSR1);
			else
				ret = kill(ft_atoi(av[1]), SIGUSR2);
			if (ret == -1)
				ft_error(2);
			j++;
		}
		i++;
	}
	return (0);
}
