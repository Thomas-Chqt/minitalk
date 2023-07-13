/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_libft2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:11:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	itoa_base_loop(unsigned long long nbr,
				size_t *i, char *buffer, char *base);

char	*strjoinf(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin((const char *)s1, (const char *)s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}

char	*create_str(char c, long n)
{
	char			*str;
	unsigned int	i;

	if (n < 0)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*itoa_base_no_minus(long long nbr, char *base)
{
	size_t	len;
	char	*buffer;
	size_t	i;

	i = 0;
	len = 0;
	len = nbr_base_len(nbr, base);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	if (nbr < 0)
		itoa_base_loop(nbr * -1, &i, buffer, base);
	else
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

size_t	nbr_base_len(long long nbr, char *base)
{
	unsigned long long	n;
	size_t				len;

	if (nbr < 0)
		n = nbr * -1;
	else
		n = nbr;
	len = 1;
	while ((n / ft_strlen(base)) > 0)
	{
		len++;
		n /= ft_strlen(base);
	}
	return (len);
}
