/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:46:00 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/30 19:46:02 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*eats_f(void *per)
{
	t_ph	*f;
	int		i;

	f = (t_ph *)per;
	i = 0;
	while (i < f->num_fil)
	{
		sem_wait(f->eats);
		i++;
	}
	i = 0;
	ft_message(*f, "Everyone has eaten enough !");
	while (i < f->num_fil)
		kill(f->pid[i++], SIGTERM);
	free(f->pid);
	sem_unlink("forks");
	sem_unlink("meals");
	exit(0);
	return (NULL);
}

void	*fil_death(void *per)
{
	t_ph	*f;
	int		i;
	int		check;

	i = 0;
	check = 1;
	f = (t_ph *)per;
	while (1)
	{
		if (ft_time() > f->last_eat + f->t_die)
		{
			ft_message(*f, "has died");
			exit(0);
		}
		else if (f->num_eat != -1 && f->eat_count >= f->num_eat && check)
		{
			sem_post(f->eats);
			check = 0;
			return (NULL);
		}
	}
	return (NULL);
}

void	fil_life(t_ph f)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, fil_death, &f);
	while (1)
	{
		sem_wait(f.forks);
		ft_message(f, "has taken a fork");
		ft_message(f, "has taken a fork");
		f.last_eat = ft_time();
		ft_message(f, "is eating");
		usleep(f.t_eat * 1000);
		f.eat_count++;
		sem_post(f.forks);
		ft_message(f, "is sleeping");
		usleep(f.t_sleep * 1000);
		ft_message(f, "is thinking");
	}
}

void	fils_born(t_ph f)
{
	pthread_t	tid;
	int			i;

	i = 0;
	f.pid = malloc(sizeof(pid_t) * f.num_fil);
	if (!f.pid)
		return ;
	i = fils_born_dop(f, i);
	if (f.num_eat > -1)
		pthread_create(&tid, NULL, eats_f, &f);
	waitpid(-1, NULL, 0);
	i = 0;
	while (i < f.num_fil)
		kill(f.pid[i++], SIGTERM);
	free(f.pid);
}

int	main(int ac, char **av)
{
	t_ph	f;

	if (arg_check(ac, av) == 0)
		return (1);
	init(&f, av, ac);
	fils_born(f);
	sem_close(f.forks);
	sem_close(f.eats);
	sem_unlink("forks");
	sem_unlink("eats");
}
