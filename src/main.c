/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:47:30 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/26 13:27:05 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_var	*var = malloc(sizeof(t_var));

	if (argc == 5 || argc == 6)
	{
		var_init(argc, argv, var);
		init_mutex(var);
		init_philo(var);
		init_thread(var);
	}
	else
	printf("Invalid number of arguments\n");
	destroy_and_free(var);
	printf("Ending\n");
}