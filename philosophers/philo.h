/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:45:52 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/30 19:45:54 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_ph
{
	pthread_mutex_t	fork;
	pthread_mutex_t	*status;
	pthread_mutex_t	*eats;
	pthread_mutex_t	*prev;
	long			start;
	long			finish;
	int				who;
	long			last_eat;
	int				num_eat;
	int				eat_count;
	int				num_fil;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				i;
}				t_ph;

void	ft_message(t_ph f, char *message);
int		arg_check(int ac, char **av);
int		ft_atoi(char *str);
void	ft_usleep(int length);
long	ft_time(void);
int		check_valid(int ac, char **av);
int		init(t_ph *f, int i, char **av, int ac);
void	fils_odd_even(t_ph *f);
void	*fils_life(void *per);
void	*eats_f(void *per);

#endif
