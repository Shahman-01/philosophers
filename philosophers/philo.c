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

void	*eats_f(void *per)
{
	t_ph	*f;
	int		i;

	f = (t_ph *)per;
	i = 0;
	if (f->num_eat != 0)
		pthread_mutex_lock(f->eats);
	while (f->num_eat != 0 && i < f->num_fil)
	{
		pthread_mutex_lock(f->eats);
		i++;
	}
	ft_message(*f, "Everyone has eaten enough !");
	pthread_mutex_unlock(f->status);
	return (NULL);
}

void	*fils_death(void *per)
{
	t_ph	*f;

	f = (t_ph *)per;
	while (1)
	{
		if (ft_time() - f->last_eat > f->t_die)
		{
			ft_message(*f, "has died");
			pthread_mutex_unlock(f->status);
			return (NULL);
		}
		else if (f->num_eat != -1 && f->eat_count >= f->num_eat)
		{
			ft_usleep((float)f->who);
			pthread_mutex_unlock(f->eats);
			return (NULL);
		}
	}
	return (NULL);
}

void	*fils_life(void *per)
{
	pthread_t	tid;
	t_ph		*f;

	f = (t_ph *)per;
	pthread_create(&tid, NULL, fils_death, f);
	fils_odd_even(f);
	while (f->num_eat == -1 || f->num_eat > f->eat_count)
	{
		pthread_mutex_lock(&f->fork);
		ft_message(*f, "haf taken a fork");
		pthread_mutex_lock(f->prev);
		ft_message(*f, "haf taken a fork");
		f->last_eat = ft_time();
		ft_message(*f, "if eating");
		ft_usleep(f->t_eat);
		pthread_mutex_unlock(&f->fork);
		pthread_mutex_unlock(f->prev);
		f->eat_count++;
		ft_message(*f, "if sleeping");
		ft_usleep(f->t_sleep);
		ft_message(*f, "is thinking");
	}
	return (NULL);
}

void	fils_born(t_ph *f)
{
	pthread_mutex_t	eats;
	pthread_mutex_t	status;
	pthread_t		tid;

	f[0].prev = &f[f[0].num_fil - 1].fork;
	pthread_mutex_init(&status, NULL);
	pthread_mutex_init(&eats, NULL);
	pthread_mutex_lock(&status);
	while (f->i < f[0].num_fil)
	{
		f[f->i].status = &status;
		f[f->i].eats = &eats;
		pthread_create(&tid, NULL, fils_life, &f[f->i++]);
	}
	if (f[0].num_eat > -1)
		pthread_create(&tid, NULL, eats_f, &f[0]);
	pthread_mutex_lock(&status);
	f->i = 0;
	while (f->i < f[0].num_fil)
		pthread_mutex_destroy(&f[f->i++].fork);
	pthread_mutex_destroy(&status);
	pthread_mutex_destroy(&eats);
	free(f);
}

int	main(int ac, char **av)
{
	t_ph	*f;
	int		i;

	i = 0;
	if (arg_check(ac, av) == 0)
		return (1);
	f = malloc(sizeof(t_ph) * ft_atoi(av[1]));
	if (!f)
		return (1);
	f->i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&f[i].fork, NULL);
		if (i != 0)
			f[i].prev = &f[i - 1].fork;
		else
			NULL;
		i = init(f, i, av, ac);
		i++;
	}
	fils_born(f);
	return (0);
}
