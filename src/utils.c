/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/26 14:25:17 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_protect(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->var->message);
	if (!philo->var->death_occured)
	printf("%lld\t%d\t%s\n", get_time(philo->var), philo->id, msg);
	pthread_mutex_unlock(&philo->var->message);
}

void	destroy_and_free(t_var *var)
{
	int i = 0;
	while (i < var->number_of_philosophers)
	{
		pthread_join(var->philo[i].t, NULL);
		i++;
	}
	i = var->number_of_philosophers;
	while (i--)
	{
		pthread_mutex_destroy(&var->forks[i]);
	}
	free(var->philo);
	free(var->forks);
	free(var);
}
