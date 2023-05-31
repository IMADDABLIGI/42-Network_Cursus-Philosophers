/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/31 15:44:52 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_list	*philo;
	t_list	*philo2;
	t_list	*tmp;
	t_data	data;
	int i = 0;

	if (ac < 5)
		ft_abort(2);
	philo = ft_parsing(NULL, av, &data);
	tmp = philo;
	philo2 = philo;
	while (i < ft_atoi(av[1]))
	{
		pthread_create(&philo->t, NULL, &execute, philo);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo2->sleep);
		if (!ft_check_dead(philo2))
			break ;
		pthread_mutex_unlock(&philo2->sleep);
		philo2 = philo2->next;
	}
	ft_destroy(tmp, 0, ft_atoi(av[1]));
	return (0);
}
