/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:09:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	parse_flag(const char *str, size_t *i, t_flag *parsed_flag)
{
	static char		flags_chars[8] = {'#', '0', '-', ' ', '+', '\''};
	unsigned int	y;

	y = 0;
	while (y <= 8)
	{
		if (str[*i] == flags_chars[y])
		{
			(*parsed_flag) = (t_flag)((unsigned char)1 << y);
			return (0);
		}
		y++;
	}
	return (-1);
}

int	parse_length_comp(const char *str, size_t *i,
		t_length_comp *parsed_length_comp)
{
	static char		*length_mod_strs[8]
		= {"hh", "h", "l", "j", "t", "z", "q", "ll"};
	unsigned int	y;

	y = 0;
	while (y <= 8)
	{
		if (ft_strncmp(str + (*i), length_mod_strs[y],
				ft_strlen(length_mod_strs[y])) == 0)
		{
			(*i) += (ft_strlen(length_mod_strs[y]) - 1);
			(*parsed_length_comp) = (t_length_comp)((unsigned char)1 << y);
			return (0);
		}
		if (y == 1)
			y = 7;
		else if (y == 7)
			y = 2;
		else if (y == 6)
			break ;
		else
			y++;
	}
	return (-1);
}

int	parse_type_comp(const char *str, size_t *i, t_type_comp *parsed_type_comp)
{
	if (ft_strchr("cspdiuxX%", str[*i]) != NULL)
	{
		(*parsed_type_comp) = (t_type_comp)str[*i];
		return (0);
	}
	return (-1);
}
