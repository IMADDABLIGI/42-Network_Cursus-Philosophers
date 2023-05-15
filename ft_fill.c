/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:40 by idabligi          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:04 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

void	ft_fill(t_data *data, char *str1, char *str2, char *str3)
{
	data->nb_p = ft_atoi(str1);
	data->tt_d = ft_atoi(str2);
	data->tt_e = ft_atoi(str3);
}

void	ft_fill2(t_data *data, char *str4, char *str5)
{
	data->tt_s= ft_atoi(str4);
	data->nb_tpe = ft_atoi(str5);
}
