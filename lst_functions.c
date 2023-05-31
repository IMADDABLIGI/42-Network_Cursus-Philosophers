/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:45:57 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/31 19:17:41 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*ptr;

	ptr = NULL;
	if (lst == NULL)
		lst = new;
	else
	{
		ptr = ft_lstlast(lst);
		ptr->next = new;
	}
	return (lst);
}

//-------------------------------------------------------------------//

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

//-------------------------------------------------------------------//

t_list	*ft_lstnew(int content)
{
	t_list	*nude;

	nude = malloc(sizeof(t_list));
	if (!nude)
		ft_abort(1);
	nude->id = content;
    nude->l_meal = ft_get_time();
    pthread_mutex_init(&nude->fork, NULL);
    pthread_mutex_init(&nude->eat, NULL);
    pthread_mutex_init(&nude->sleep, NULL);
	nude->next = NULL;
	return (nude);
}
