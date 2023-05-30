/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:50 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/30 19:22:49 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

void	ft_printf(char *str, t_list *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s", (ft_get_time() - philo->data->bg_time), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

//----------------------------------------------------------------------------//

void	ft_usleep(t_list *philo, long long timeof)
{
	long long	time;

	pthread_mutex_lock(&philo->sleep);
	timeof = timeof / 1000;
	time = ft_get_time() + timeof;
	while (ft_get_time() < time)
		usleep(50);
	pthread_mutex_unlock(&philo->sleep);
}

//----------------------------------------------------------------------------//

void	*execute(void *arg)
{
	t_list	*philo;
	int i = 0;

	philo = (t_list *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		ft_printf("has taken a fork\n", philo);
		pthread_mutex_lock(&philo->next->fork);
		ft_printf("has taken a fork\n", philo);
		ft_printf("is eating\n", philo);
		
		ft_usleep(philo, philo->data->t_eat);
		// usleep(philo->data->t_eat);

		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_printf("is sleeping\n", philo);
		
		ft_usleep(philo, philo->data->t_sleep);
		// usleep(philo->data->t_sleep);

		ft_printf("is thinking\n", philo);
		usleep(60);
	}
	return (NULL);
}

//----------------------------------------------------------------------------//
