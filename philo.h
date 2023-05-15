/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:07:47 by idabligi          #+#    #+#             */
/*   Updated: 2023/03/07 15:00:17 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	data
{
	int		nb_p;
	int		tt_d;
	int		tt_e;
	int		tt_s;
	int		nb_tpe;
}	t_data;

void	ft_fill(t_data *data, char *str1, char *str2, char *str3);
void	ft_fill2(t_data *data, char *str4, char *str5);

#endif