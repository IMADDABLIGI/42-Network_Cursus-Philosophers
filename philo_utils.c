/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:27:34 by idabligi          #+#    #+#             */
/*   Updated: 2023/05/30 13:35:39 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_abort(int id)
{
	if (id == 1)
		printf("\e[1;31mmalloc problem\n\e[0m");
	else if (id == 2)
		printf("\e[1;31mArgument please!\n\e[0m");
	exit(1);
}

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	unsigned long	rst;

	i = 0;
	rst = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		rst = rst * 10 + str[i++] - '0';
    if (!(str[i] >= '0' && str[i] <= '9') && (str[i]))
        ft_abort(2);
	return ((int)rst * sign);
}
