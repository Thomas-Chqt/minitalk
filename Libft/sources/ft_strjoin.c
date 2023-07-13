/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:51:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:22:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*output_str;
	unsigned long long	output_str_len;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	output_str_len = ft_strlen(s1) + ft_strlen(s2);
	output_str = malloc(sizeof(char) * (output_str_len + 1));
	if (!output_str)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		output_str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		output_str[i + j] = s2[j];
		j++;
	}
	output_str[i + j] = '\0';
	return (output_str);
}
