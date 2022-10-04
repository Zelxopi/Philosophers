/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:02:15 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/04 15:05:14 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	var_init(int argc, char **argv, t_var *var)
{
	var->number_of_philosophers = philo_atoi(argv[1]);
	var->time_to_die = philo_atoi(argv[2]);
	var->time_to_eat = philo_atoi(argv[3]);
	var->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
	var->number_of_times_eat = philo_atoi(argv[5]);
	else
	var->number_of_times_eat = 0;
}

int	philo_atoi(const char *str)
{
	long long	nb;
	long long	negative;

	nb = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		ft_error("Invalid argument");
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			nb = nb * 10 + (*str - '0');
			if ((nb * negative) > INT_MAX || (nb * negative) < INT_MIN)
				ft_error("Does not fit an int");
			str++;
		}
		else
			ft_error("Invalid argument");
	}
	return (nb * negative);
}
