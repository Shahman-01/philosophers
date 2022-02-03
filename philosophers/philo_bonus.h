/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:46:07 by ppeapod           #+#    #+#             */
/*   Updated: 2021/12/30 19:46:09 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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
	sem_t	*forks;
	sem_t	*eats;
	pid_t	*pid;
	long	start;
	long	finish;
	int		who;
	long	last_eat;
	int		num_eat;
	int		eat_count;
	int		num_fil;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		t_think;
}				t_ph;

void	ft_message(t_ph f, char *message);
int		arg_check(int ac, char **av);
int		ft_atoi(char *str);
void	ft_usleep(int length);
long	ft_time(void);
void	init(t_ph *f, char **av, int ac);
int		fils_born_dop(t_ph f, int i);
void	fil_life(t_ph f);

#endif
