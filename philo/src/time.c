/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:45:08 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/31 13:48:46 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	get_time(t_var *var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (!var->start)
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	else
		return (((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000))
			- var->start);
}

void	timer(t_var *var, int wait_time)
{
	long long	start;

	start = get_time(var);
	while ((get_time(var) - start) < wait_time)
		usleep(50);
	return ;
}

void	*death_thread(void *var_void)
{
	int		i;
	t_var	*var;

	var = var_void;
	while (!var->death_occured)
	{
		i = 0;
		while (i < var->number_of_philosophers)
		{
			if ((var->philo[i].death)
				&& ((get_time(var) - var->philo[i].last_meal)
					>= var->time_to_die))
			{
				print_protect(&var->philo[i], "died");
				var->death_occured = 1;
				pthread_join(var->charron, NULL);
			}
			i++;
		}
	}
	return (0);
}

int	full_of_spaghetti(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->number_of_philosophers)
	{
		if (var->philo[i].nb_of_meal > 0)
			return (0);
		i++;
	}
	return (1);
}
