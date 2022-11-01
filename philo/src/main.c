/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:47:30 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/31 13:57:13 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_var	*var;

	var = ft_calloc(1, sizeof(t_var));
	if (argc == 5 || argc == 6)
	{
		var_init(argc, argv, var);
		if (!var->error)
		{
			init_mutex(var);
			init_philo(var);
			init_thread(var);
			destroy_and_free(var);
		}
		else
		{
			printf("Invalid argument\n");
		}
	}
	else
		printf("Invalid number of arguments\n");
	free(var);
}
