/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:45:43 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/30 19:45:45 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_ph *f, int i, char **av, int ac)
{
	f[i].num_fil = ft_atoi(av[1]);
	f[i].t_die = ft_atoi(av[2]);
	f[i].t_eat = ft_atoi(av[3]);
	f[i].t_sleep = ft_atoi(av[4]);
	f[i].start = ft_time();
	if (ac == 6)
		f[i].num_eat = ft_atoi(av[5]);
	else
		f[i].num_eat = -1;
	f[i].last_eat = f[i].start;
	f[i].eat_count = 0;
	f[i].who = i + 1;
	return (i);
}

void	fils_odd_even(t_ph *f)
{
	if (f->who % 2 == 0)
	{
	}
	else
		ft_usleep((float)f->t_eat * 0.9 + 1);
}
