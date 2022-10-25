/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:22:24 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/25 16:03:46 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void *routine(void *philo_void)
{
	t_philo *philo;
	
	philo = philo_void;
	while(!philo->var->death_occured)
	{
		taking_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return(0);
}

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->var->forks[philo->r_fork]);
	philo->death = 0;
	printf("%lld\t%d\thas taken forks %d and %d\n", get_time(philo->var), philo->id, philo->l_fork, philo->r_fork);
}

void	eating(t_philo *philo)
{
	printf("%lld\t%d\tis eating\n", get_time(philo->var), philo->id);
	timer(philo->var, philo->var->time_to_eat);
	pthread_mutex_unlock(&philo->var->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->var->forks[philo->r_fork]);
	philo->death = 1;
	philo->last_meal = get_time(philo->var);
}

void	sleeping(t_philo *philo)
{
	printf("%lld\t%d\tis sleeping\n", get_time(philo->var), philo->id);
	timer(philo->var, philo->var->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	printf("%lld\t%d\tis thinking\n", get_time(philo->var), philo->id);
}