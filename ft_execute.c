/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:50 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/31 17:42:56 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

void	ft_printf(char *str, t_list *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->is_dead)
    	printf("%lld %d %s", (ft_get_time() - philo->data->bg_time), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

//----------------------------------------------------------------------------//

void	ft_usleep(t_list *philo, long long timeof, int check)
{
	long long	time;

	time = ft_get_time() + timeof;
	if (check)
	{
		philo->l_meal = ft_get_time();
		while (ft_get_time() < time)
		usleep(50);
	}
	else 
	{
		while (ft_get_time() < time)
			usleep(50);
	}
}

//----------------------------------------------------------------------------//

int	ft_check_dead(t_list *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (((ft_get_time()) - philo->l_meal) > philo->data->t_die)
	{
		ft_printf("died\n", philo);
		philo->data->is_dead = 0;
		return (0);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (1);
}

//----------------------------------------------------------------------------//

int	ft_check_exit(t_list *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (!philo->data->is_dead)
		return (0);
	pthread_mutex_unlock(&philo->data->dead);
	return (1);
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
		if (!ft_check_exit(philo))
			break ;
		pthread_mutex_lock(&philo->fork);
		ft_printf("has taken a fork\n", philo);
		if (!ft_check_exit(philo))
			break ;
		pthread_mutex_lock(&philo->next->fork);
		ft_printf("has taken a fork\n", philo);
		pthread_mutex_lock(&philo->eat);
		ft_printf("is eating\n", philo);
		ft_usleep(philo, philo->data->t_eat, 1);
		pthread_mutex_unlock(&philo->eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_printf("is sleeping\n", philo);
		ft_usleep(philo, philo->data->t_sleep, 0);
		ft_printf("is thinking\n", philo);
	}
	return (NULL);
}

//----------------------------------------------------------------------------//