/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/25 16:01:23 by mtrembla         ###   ########.fr       */
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
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_eat;
	long long start;
	pthread_mutex_t *forks;
	pthread_t	charron;
	int death_occured;
	struct s_philo	*philo;
}	t_var;

typedef struct s_philo
{
	pthread_t	t;
	int death;
	int	id;
	int l_fork;
	int	r_fork;
	long long	last_meal;
	struct s_var *var;
}	t_philo;

//parsing
int		philo_atoi(const char *str);
void	var_init(int argc, char **argv, t_var *var);
void	init_mutex(t_var *var);
void	init_philo(t_var *var);
void	init_thread(t_var *var);
//utils
void	ft_error(char *str);
void	mutex_destroy(t_var *var);
//actions
void	*routine(void *);
void	taking_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
//time
long long	get_time(t_var *var);
void	timer(t_var *var, int wait_time);
void	*death_thread(void *);


#endif