/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_converted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:42:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	(*get_put_func(t_type_comp conv_type))(t_conv_specs conv_specs,
		t_arg_list *args);

int	print_converted(const char *str, size_t *i, t_arg_list *args,
		size_t *print_count)
{
	t_conv_specs	conv_specs;
	int				(*put_func)(t_conv_specs conv_specs, t_arg_list *args);

	if (parse_conv_specs(str, i, args, &conv_specs) != 0)
		return (0);
	put_func = get_put_func(conv_specs.conversion_type);
	if (put_func == NULL)
		return (free_conv_specs(conv_specs));
	(*print_count) += put_func(conv_specs, args);
	free_conv_specs(conv_specs);
	return (0);
}

int	(*get_put_func(t_type_comp conv_type))(t_conv_specs conv_specs,
		t_arg_list *args)
{
	if (conv_type == c)
		return (&put_c);
	if (conv_type == s)
		return (&put_s);
	if (conv_type == u)
		return (&put_u);
	if (conv_type == x)
		return (&put_x);
	if (conv_type == upx)
		return (&put_upx);
	if (conv_type == p)
		return (&put_x);
	if (conv_type == perc)
		return (&put_per);
	if (conv_type == d || conv_type == i)
		return (&put_di);
	return (NULL);
}
