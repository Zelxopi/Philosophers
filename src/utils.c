/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/13 16:00:30 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void ft_error(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	exit(0);
}

void *routine(void *philo_void)
{
	t_philo *philo;
	
	philo = philo_void;
	taking_forks(philo);
	eating(philo);
	printf("%d is sleeping\n", philo->id);
	printf("%d is thinking\n", philo->id);
	return(0);
}

void	mutex_destroy(t_var *var)
{
	int i = var->number_of_philosophers;
	while (i--)
	{
		pthread_mutex_destroy(&var->forks[i]);
	}
}
