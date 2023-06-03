/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:50 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/03 14:39:30 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

void	ft_printf(char *str, t_list *philo, long long time)
{
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->dead);
	time = ft_get_time() - philo->data->bg_time;
	printf("%lld %d %s", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->dead);
	pthread_mutex_unlock(&philo->data->print);
}

//----------------------------------------------------------------------------//

void	ft_usleep1(t_list *philo, long long timeof)
{
	long long	time;

	time = ft_get_time() + timeof;
	pthread_mutex_lock(&philo->meal);
	philo->l_meal = ft_get_time();
	pthread_mutex_unlock(&philo->meal);
	pthread_mutex_lock(&philo->data->stop);
	while (ft_get_time() < time)
		usleep(50);
	pthread_mutex_lock(&philo->cnt_eat);
	philo->count_e++;
	pthread_mutex_unlock(&philo->cnt_eat);
	pthread_mutex_unlock(&philo->data->stop);
}

//----------------------------------------------------------------------------//

void	ft_usleep2(long long timeof)
{
	long long	time;

	time = ft_get_time() + timeof;
	while (ft_get_time() < time)
		usleep(50);
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
		pthread_mutex_lock(&philo->eat);
		ft_printf("is eating\n", philo, 0);
		pthread_mutex_unlock(&philo->eat);
		ft_usleep1(philo, philo->data->t_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_printf("is sleeping\n", philo, 0);
		ft_usleep2(philo->data->t_sleep);
		ft_printf("is thinking\n", philo, 0);
		usleep(50);
	}
	return (NULL);
}

//----------------------------------------------------------------------------//