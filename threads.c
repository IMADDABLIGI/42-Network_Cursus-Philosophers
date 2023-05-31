/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/31 19:42:10 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

int	ft_check_dead(t_list *philo, long long t_dead)
{
	pthread_mutex_lock(&philo->sleep);
	if (((ft_get_time()) - philo->l_meal) > philo->data->t_die)
	{
		philo->data->is_dead = 0;
		t_dead = (ft_get_time() - philo->data->bg_time);
		printf("%lld %d died\n", t_dead, philo->id);
		return (0);
	}
	pthread_mutex_unlock(&philo->sleep);
	return (1);
}

//----------------------------------------------------------------------------//

int	main(int ac, char **av)
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
		pthread_mutex_lock(&philo2->eat);
		if (!ft_check_dead(philo2, 0))
		{
			ft_destroy(tmp, 0, ft_atoi(av[1]));
			return (1);
		}
		pthread_mutex_unlock(&philo2->eat);
		philo2 = philo2->next;
	}
	return (0);
}
