/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/24 15:13:07 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void ft_error(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	exit(0);
}

void	mutex_destroy(t_var *var)
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
