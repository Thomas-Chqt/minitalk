/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:07:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:22:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static long			ft_long_atoi(const char *str);
static unsigned int	find_first_index(const char *str);

int	ft_atoi(const char *str)
{
	return ((int)ft_long_atoi(str));
}

static long	ft_long_atoi(const char *str)
{
	char			signe;
	long			nbr;
	unsigned int	i;

	signe = 1;
	nbr = 0;
	i = find_first_index(str);
	if (str[i] == '-')
		signe *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr > LONG_MAX / 10)
			|| (nbr == LONG_MAX / 10 && str[i] - '0' > LONG_MAX % 10))
		{
			if (signe == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (signe * nbr);
}

static unsigned int	find_first_index(const char *str)
{
	unsigned int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	return (i);
}
