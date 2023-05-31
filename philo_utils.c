/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:27:34 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/31 19:44:58 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------------------------------------------------------------------//

void	ft_abort(int id)
{
	if (id == 1)
		printf("\e[1;31mmalloc problem\n\e[0m");
	else if (id == 2)
		printf("\e[1;31mArgument please!\n\e[0m");
	exit(1);
}

//----------------------------------------------------------------------------//

void	ft_destroy(t_list *philo, int i, int limit)
{
	pthread_mutex_destroy(&philo->data->print);
	while(i < limit)
	{
		pthread_mutex_destroy(&philo->eat);
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->sleep);
        pthread_detach(philo->t);
		philo = philo->next;
		i++;
	}
}

//----------------------------------------------------------------------------//

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	unsigned long	rst;

	i = 0;
	rst = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		rst = rst * 10 + str[i++] - '0';
    if (!(str[i] >= '0' && str[i] <= '9') && (str[i]))
        ft_abort(2);
	return ((int)rst);
}
