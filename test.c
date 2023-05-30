/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:22:32 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/27 17:14:03 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func()
{
	int value;
	int *res;
	
	value = 50;
	printf("hello how are u \n");
	res = malloc(sizeof(int));
	*res = value;
	printf("    %p\n", res);
	return res;
}

int main()
{
	pthread_t a;
	int	*check;

	pthread_create(&a, NULL, &func, NULL);
	pthread_join(a, (void *)&check);
	
	printf("    %p\n\n", check);
	printf("%d", *check);
}
