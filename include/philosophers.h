/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/04 15:06:20 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_var
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_eat;
}	t_var;

//parsing
int		philo_atoi(const char *str);
void	var_init(int argc, char **argv, t_var *var);
//utils
void ft_error(char *str);

#endif