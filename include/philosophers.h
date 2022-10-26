/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/26 14:18:07 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_var
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_eat;
	int				death_occured;
	int				error;
	long long		start;
	pthread_t		charron;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	struct s_philo	*philo;
}	t_var;

typedef struct s_philo
{
	int				id;
	int				death;
	int				l_fork;
	int				r_fork;
	pthread_t		t;
	long long		last_meal;
	struct s_var	*var;
}	t_philo;

//parsing
int			philo_atoi(const char *str, t_var *var);
void		var_init(int argc, char **argv, t_var *var);
void		init_mutex(t_var *var);
void		init_philo(t_var *var);
void		init_thread(t_var *var);
//utils
void		print_protect(t_philo *philo, char *msg);
void		destroy_and_free(t_var *var);
//actions
void		*routine(void *philo_void);
void		taking_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
//time
long long	get_time(t_var *var);
void		timer(t_var *var, int wait_time);
void		*death_thread(void *var_void);

#endif