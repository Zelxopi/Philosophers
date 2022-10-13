/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:22:24 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/13 15:57:42 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->var->forks[philo->r_fork]);
	printf("%d has taken forks %d and %d\n", philo->id, philo->l_fork, philo->r_fork);
}

void	eating(t_philo *philo)
{
	printf("%d is eating\n", philo->id);
	sleep(1);
	pthread_mutex_unlock(&philo->var->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->var->forks[philo->r_fork]);
}

// void	sleeping(t_philo *philo)
// {

// }

// void	thinking(t_philo *philo)
// {

// }