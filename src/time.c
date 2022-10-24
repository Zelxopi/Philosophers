/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:45:08 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/24 15:07:06 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	get_time(t_var *var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (!var->start)
	return((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	else
	return(((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000)) - var->start);
}

void	timer(t_var *var, int wait_time)
{
	long long start;

	start = get_time(var);
	while ((get_time(var) - start) < wait_time)
		usleep(1);
	return;
}