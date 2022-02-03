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

#include "philo_bonus.h"

void	init(t_ph *f, char **av, int ac)
{
	f->num_fil = ft_atoi(av[1]);
	f->t_die = ft_atoi(av[2]);
	f->t_eat = ft_atoi(av[3]);
	f->t_sleep = ft_atoi(av[4]);
	f->start = ft_time();
	f->last_eat = f->start;
	f->eat_count = 0;
	if (ac == 6)
		f->num_eat = ft_atoi(av[5]);
	else
		f->num_eat = -1;
	sem_unlink("forks");
	sem_unlink("eats");
	f->forks = sem_open("forks", O_CREAT, S_IRWXU, (f->num_fil / 2));
	if (f->forks == SEM_FAILED)
		exit(1);
	f->eats = sem_open("eats", O_CREAT, S_IRWXU, 0);
}

int	fils_born_dop(t_ph f, int i)
{
	while (i < f.num_fil)
	{
		f.pid[i] = fork();
		if (f.pid[i] == 0)
		{
			f.who = i + 1;
			fil_life(f);
			i = f.num_fil;
		}
		i++;
		usleep(500);
	}
	return (i);
}
