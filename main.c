/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:55:34 by idabligi          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:11 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac < 5)
	{
		printf("Error: check Arguments!");
		return (0);
	}
	ft_fill(&data, av[1], av[2], av[3]);
	ft_fill2(&data, av[4], av[5]);
	printf("In table we have\n");
	printf("nb_p :%d | tt_d :%d | tt_e :%d | tt_s :%d | nb_tpe :%d\n", data.nb_p, data.tt_d, data.tt_e, data.tt_s, data.nb_tpe);
	return (0);
}