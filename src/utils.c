/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/12 16:02:31 by mtrembla         ###   ########.fr       */
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
	pthread_mutex_lock(philo->var->forks);
	printf("%d has taken a fork\n", philo->id);
	printf("%d is eating\n", philo->id);
	pthread_mutex_unlock(philo->var->forks);
	printf("%d is sleeping\n", philo->id);
	printf("%d is thinking\n", philo->id);
	return(0);
}
