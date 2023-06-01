/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:28:24 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/01 14:58:54 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct data
{
	long long			bg_time;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					is_dead;
	pthread_mutex_t		print;
	pthread_mutex_t		cnt_eat;
}	t_data;

typedef struct l_data
{
	int					id;
	int					check_eat;
	int					count_e;
	long long			l_meal;
	pthread_t			t;
	pthread_mutex_t		fork;
	pthread_mutex_t		sleep;
	t_data				*data;
	struct l_data		*next;
}	t_list;

long long	ft_get_time(void);
void		ft_abort(int id);
int			ft_atoi(char *str);
void		*execute(void *arg);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstadd_back(t_list *lst, t_list *new);
t_list		*ft_parsing(t_list *philo, char **av, t_data *data);
int			ft_check_dead(t_list *philo, long long t_dead);
void		ft_destroy(t_list *philo, int i, int limit);

#endif