/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:25:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	itoa_base_loop(unsigned long long nbr,
				size_t *i, char *buffer, char *base);

unsigned int	ft_atoi_uint(const char *str)
{
	unsigned int	nbr;
	unsigned int	i;

	nbr = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr);
}

size_t	put_n_c(size_t n, size_t minus, char c)
{
	size_t	i;

	if (minus >= n)
		return (0);
	i = 0;
	while (i < (n - minus))
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (n - minus);
}

char	*itoa_base(unsigned long long nbr, char *base)
{
	size_t	len;
	char	*buffer;
	size_t	i;

	i = 0;
	len = 0;
	len = unbr_base_len(nbr, base);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	itoa_base_loop(nbr, &i, buffer, base);
	buffer[i] = '\0';
	return (buffer);
}

static void	itoa_base_loop(unsigned long long nbr,
				size_t *i, char *buffer, char *base)
{
	if ((nbr / ft_strlen(base)) > 0)
	{
		itoa_base_loop(nbr / ft_strlen(base), i, buffer, base);
	}
	buffer[*i] = base[nbr % ft_strlen(base)];
	(*i)++;
}

size_t	unbr_base_len(unsigned long long nbr, char *base)
{
	unsigned long long	n;
	size_t				len;

	n = nbr;
	len = 1;
	while ((n / ft_strlen(base)) > 0)
	{
		len++;
		n /= ft_strlen(base);
	}
	return (len);
}
