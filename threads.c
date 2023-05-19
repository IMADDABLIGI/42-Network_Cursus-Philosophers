/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/19 21:56:29 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print()
{
	printf("Done Succecfely\n");
	return (0);
}

void	ft_function(pthread_t )
int main(int ac, char **av)
{
	pthread_t	t[ac];
	pthread_create(&t, NULL, &print, NULL);
	pthread_join(t, NULL);
	return (0);
}