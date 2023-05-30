/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/30 17:13:47 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_list	*philo;
	t_list	*tmp;
	t_data	data;
	int i = 0;

	if (ac < 5)
		ft_abort(2);
	philo = ft_parsing(NULL, av, &data);
	tmp = philo;
	while (i < ft_atoi(av[1]))
	{
		pthread_create(&philo->t, NULL, &execute, philo);
		philo = philo->next;
		i++;
	}
	i = 0;
	while(i < ft_atoi(av[1]))
	{
		// pthread_detach(tmp->t);
		pthread_join(tmp->t, NULL);
		pthread_mutex_destroy(&tmp->fork);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
