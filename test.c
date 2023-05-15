/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:39:09 by idabligi          #+#    #+#             */
/*   Updated: 2023/03/07 19:08:56 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>

void *myThreadFun()
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
   
void *myThreadFun2()
{
    // sleep(1);
    printf("Printing GeeksQuiz from Thread22 \n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    pthread_t thread_id2;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun2, NULL);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
    printf("After Thread\n");
    exit(0);
}