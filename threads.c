/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/03 14:39:44 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

int	ft_check_dead(t_list *philo, long long t_dead)
{
	pthread_mutex_lock(&philo->meal);
	if (((ft_get_time()) - philo->l_meal) > philo->data->t_die)
	{
		pthread_mutex_lock(&philo->data->dead);
		t_dead = (ft_get_time() - philo->data->bg_time);
		printf("%lld %d died\n", t_dead, philo->id);
		return (0);
	}
	pthread_mutex_unlock(&philo->meal);
	return (1);
}

//----------------------------------------------------------------------------//

int	ft_check_count(t_list *philo, char **av, int i, int count)
{
	int	done;

	if (av[5])
	{
		done = ft_atoi(av[5]);
		pthread_mutex_lock(&philo->data->stop);
		while (i < ft_atoi(av[1]))
		{
			pthread_mutex_lock(&philo->cnt_eat);
			if (philo->count_e >= done)
				count++;
			else
			{
				pthread_mutex_unlock(&philo->cnt_eat);
				break ;
			}
			pthread_mutex_unlock(&philo->cnt_eat);
			philo = philo->next;
			i++;
		}
		pthread_mutex_unlock(&philo->data->stop);
		if (count == ft_atoi(av[1]))
			return (0);
	}
	return (1);
}

//----------------------------------------------------------------------------//

int	ft_end_thread(t_list *philo, t_list *tmp, char **av)
{
	while (1)
	{
		if (!ft_check_count(tmp, av, 0, 0))
		{
			ft_destroy(tmp, 0, ft_atoi(av[1]));
			return (0);
		}
		pthread_mutex_lock(&philo->eat);
		if (!ft_check_dead(philo, 0))
		{
			ft_destroy(tmp, 0, ft_atoi(av[1]));
			return (1);
		}
		pthread_mutex_unlock(&philo->eat);
		philo = philo->next;
	}
	return (0);
}

//----------------------------------------------------------------------------//

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*philo;
	t_list	*tmp;
	int		i;

	i = 0;
	if (ac < 5 || ac > 6 || !ft_atoi(av[1]))
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
	if (ft_end_thread(tmp, tmp, av))
		return (1);
	return (0);
}
