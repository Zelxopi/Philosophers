/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:22:24 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/31 16:12:38 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *philo_void)
{
	t_philo	*philo;

	philo = philo_void;
	if (philo->var->number_of_philosophers < 2)
		timer(philo->var, philo->var->time_to_die + 10);
	while (!philo->var->death_occured)
	{
		taking_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->var->forks[philo->r_fork]);
	philo->death = 0;
	print_protect(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	print_protect(philo, "is eating");
	timer(philo->var, philo->var->time_to_eat);
	philo->nb_of_meal--;
	if (philo->var->number_of_times_eat && full_of_spaghetti(philo->var))
		{
			philo->var->death_occured = 1;
			printf("%lld\tEveryone is full of spaghetti\n", get_time(philo->var));
		}
	pthread_mutex_unlock(&philo->var->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->var->forks[philo->r_fork]);
	philo->last_meal = get_time(philo->var);
	philo->death = 1;
}

void	sleeping(t_philo *philo)
{
	print_protect(philo, "is sleeping");
	timer(philo->var, philo->var->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_protect(philo, "is thinking");
}
