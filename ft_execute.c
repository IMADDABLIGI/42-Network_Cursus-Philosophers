/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:50 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/01 15:18:21 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

void	ft_printf(char *str, t_list *philo, long long time)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->is_dead)
	{
		time = ft_get_time() - philo->data->bg_time;
		printf("%lld %d %s", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->print);
}

//----------------------------------------------------------------------------//

void	ft_usleep(t_list *philo, long long timeof, int check)
{
	long long	time;

	pthread_mutex_lock(&philo->sleep);
	time = ft_get_time() + timeof;
	if (check)
	{
		philo->l_meal = ft_get_time();
		while (ft_get_time() < time)
			usleep(50);
		pthread_mutex_lock(&philo->data->cnt_eat);
		philo->count_e++;
		pthread_mutex_unlock(&philo->data->cnt_eat);
	}
	else
	{
		while (ft_get_time() < time)
			usleep(50);
	}
	pthread_mutex_unlock(&philo->sleep);
}

//----------------------------------------------------------------------------//

void	*execute(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		ft_printf("has taken a fork\n", philo, 0);
		pthread_mutex_lock(&philo->next->fork);
		ft_printf("has taken a fork\n", philo, 0);
		philo->check_eat = 1;
		ft_printf("is eating\n", philo, 0);
		ft_usleep(philo, philo->data->t_eat, 1);
		philo->check_eat = 0;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_printf("is sleeping\n", philo, 0);
		ft_usleep(philo, philo->data->t_sleep, 0);
		ft_printf("is thinking\n", philo, 0);
		usleep(50);
	}
	return (NULL);
}

//----------------------------------------------------------------------------//