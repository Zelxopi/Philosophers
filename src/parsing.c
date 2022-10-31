/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:02:15 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/31 13:57:08 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_atoi(const char *str, t_var *var)
{
	long long	nb;

	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			nb = nb * 10 + (*str - '0');
			if (nb > INT_MAX || nb < INT_MIN)
				return (var->error = 1);
			str++;
		}
		else
			return (var->error = 1);
	}
	return (nb);
}

void	var_init(int argc, char **argv, t_var *var)
{
	var->error = '\0';
	var->number_of_philosophers = philo_atoi(argv[1], var);
	var->time_to_die = philo_atoi(argv[2], var);
	var->time_to_eat = philo_atoi(argv[3], var);
	var->time_to_sleep = philo_atoi(argv[4], var);
	var->start = get_time(var);
	var->death_occured = '\0';
	if (argc == 6)
		var->number_of_times_eat = philo_atoi(argv[5], var);
	else
		var->number_of_times_eat = '\0';
}

void	init_mutex(t_var *var)
{
	int	i;

	i = 0;
	var->forks = malloc(sizeof(pthread_mutex_t) * var->number_of_philosophers);
	while (i < var->number_of_philosophers)
	{
		pthread_mutex_init(&var->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&var->message, NULL);
}

void	init_philo(t_var *var)
{
	int	i;

	i = 0;
	var->philo = malloc(sizeof(t_philo) * var->number_of_philosophers);
	while (i < var->number_of_philosophers)
	{
		var->philo[i].l_fork = i;
		var->philo[i].r_fork = (i + 1) % var->number_of_philosophers;
		var->philo[i].id = i + 1;
		var->philo[i].var = var;
		var->philo[i].last_meal = 0;
		var->philo[i].death = 1;
		var->philo[i].nb_of_meal = var->number_of_times_eat;
		i++;
	}
}

void	init_thread(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->number_of_philosophers)
	{
		pthread_create(&var->philo[i].t, NULL, &routine,
			(void *)&var->philo[i]);
		i++;
	}
	pthread_create(&var->charron, NULL, &death_thread, (void *) var);
}
