/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:47:30 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/12 13:55:37 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_var	var;
	int	i = 0;

	if (argc == 5 || argc == 6)
	{
		var_init(argc, argv, &var);
		init_philo(&var);
		init_thread(&var);
	}
	else
	ft_error("Invalid number of arguments");
	while (i < var.number_of_philosophers)
	printf("philo ID: %d\n", var.philo[i++].id);
}