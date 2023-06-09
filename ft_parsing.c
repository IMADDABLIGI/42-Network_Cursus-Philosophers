/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:11:30 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/03 14:39:32 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

long long	ft_get_time(void)
{
	struct timeval		rt;
	long long			time;

	gettimeofday(&rt, NULL);
	time = (rt.tv_sec) * 1000 + (rt.tv_usec) / 1000;
	return (time);
}

//----------------------------------------------------------------------------//

t_list	*ft_get_data(t_list *philo, t_list *tmp, char **str, t_data *data)
{
	data->t_die = ft_atoi(str[2]);
	data->t_eat = ft_atoi(str[3]);
	data->t_sleep = ft_atoi(str[4]);
	if (str[5])
		ft_atoi(str[5]);
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
		ft_abort(1);
	while (philo)
	{
		philo->data = data;
		philo = philo->next;
	}
	philo = tmp;
	return (philo);
}

//----------------------------------------------------------------------------//

t_list	*ft_parsing(t_list *philo, char **av, t_data *data)
{
	int		i;
	t_list	*tmp;

	i = 0;
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->stop, NULL);
	while (i < ft_atoi(av[1]))
	{
		philo = ft_lstadd_back(philo, ft_lstnew(i + 1));
		i++;
	}
	philo = ft_get_data(philo, philo, av, data);
	tmp = philo;
	tmp = ft_lstlast(tmp);
	tmp->next = philo;
	data->bg_time = ft_get_time();
	return (philo);
}
