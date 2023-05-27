/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/27 14:22:04 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print(void *arg)
{
	t_list	*data;
	int		i = 0;

	data = (t_list *)arg;
		pthread_mutex_lock(&data->lock);
	while (i < 5000000)
	{
		data->i++;
		i++;
	}
	printf("sum : |%d|\n", data->i);
		pthread_mutex_unlock(&data->lock);
	return (NULL);
}

int main(int ac, char **av)
{
	t_list		data;
	pthread_t	t[2];
	int i = 0;

	data.i = 0;
	pthread_mutex_init(&data.lock, NULL);

	pthread_create(&t[0], NULL, &print, (void *)&data);
	pthread_create(&t[1], NULL, &print, (void *)&data);

	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
    pthread_mutex_destroy(&data.lock);
	return (0);
}
