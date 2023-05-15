/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:48:19 by idabligi          #+#    #+#             */
/*   Updated: 2023/03/08 19:25:47 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int num = 0;
pthread_mutex_t lock;

void    *ft_print()
{
	int i = 0;

	while (i < 1000000)
	{
		pthread_mutex_lock(&lock);
		num++;
		i++;
		pthread_mutex_unlock(&lock);
	}
	return (0);
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_mutex_init(&lock, NULL);
	printf("Before Threads : \n");
	pthread_create(&t1, NULL, ft_print, NULL);
	pthread_create(&t2, NULL, ft_print, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("number is : %d\n", num);
}
