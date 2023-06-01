/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/01 15:47:03 by idabligi         ###   ########.fr       */
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
		pthread_mutex_unlock(&philo->sleep);
		return (0);
	}
	pthread_mutex_unlock(&philo->sleep);
	return (1);
}

//----------------------------------------------------------------------------//

int	ft_check_count(t_list *philo, char **av, int limit, int count)
{
	int	i;
	int	done;

	i = 0;
	if (!av[5])
		return (1);
	done = ft_atoi(av[5]);
	pthread_mutex_lock(&philo->data->cnt_eat);
	while (i < limit)
	{
		if (philo->count_e >= done)
			count++;
		else
		{
			pthread_mutex_unlock(&philo->data->cnt_eat);
			return (1);
		}
		philo = philo->next;
		i++;
	}
	pthread_mutex_unlock(&philo->data->cnt_eat);
	if (count == limit)
		return (0);
	return (1);
}

//----------------------------------------------------------------------------//

int	ft_end_thread(t_list *philo, t_list *tmp, char **av)
{
	while (1)
	{
		usleep(50);
		if (philo->check_eat)
			philo = philo->next;
		if (!ft_check_dead(philo, 0))
		{
			ft_destroy(tmp, 0, ft_atoi(av[1]));
			return (1);
		}
		if (!ft_check_count(tmp, av, ft_atoi(av[1]), 0))
		{
			ft_destroy(tmp, 0, ft_atoi(av[1]));
			return (0);
		}
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
