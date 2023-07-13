/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:06:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	put_c(t_conv_specs conv_specs, t_arg_list *args)
{
	int		print_count;
	char	padding_char;

	print_count = 0;
	padding_char = ' ';
	if ((conv_specs.flags & zero) == zero)
		padding_char = '0';
	if ((conv_specs.flags & minus) != minus)
		print_count += put_n_c(conv_specs.width, 1, padding_char);
	ft_putchar_fd((char)get_arg(conv_specs.arg_index, args), 1);
	print_count++;
	if ((conv_specs.flags & minus) == minus)
		print_count += put_n_c(conv_specs.width, 1, padding_char);
	return (print_count);
}

int	put_s(t_conv_specs conv_specs, t_arg_list *args)
{
	int		print_count;
	char	padding_char;
	char	*str;
	char	*arg_str;

	print_count = 0;
	padding_char = ' ';
	if ((conv_specs.flags & zero) == zero)
		padding_char = '0';
	arg_str = (char *)get_arg(conv_specs.arg_index, args);
	if (arg_str == NULL)
		arg_str = "(null)";
	if (conv_specs.precision)
		str = ft_substr(arg_str, 0, *(conv_specs.precision));
	else
		str = ft_strdup(arg_str);
	if ((conv_specs.flags & minus) != minus)
		print_count += put_n_c(conv_specs.width, ft_strlen(str), padding_char);
	ft_putstr_fd(str, 1);
	print_count += ft_strlen(str);
	if ((conv_specs.flags & minus) == minus)
		print_count += put_n_c(conv_specs.width, ft_strlen(str), padding_char);
	free(str);
	return (print_count);
}

int	put_per(t_conv_specs conv_specs, t_arg_list *args)
{
	int		print_count;
	char	padding_char;

	if (args == 0)
	{
	}
	print_count = 0;
	padding_char = ' ';
	if ((conv_specs.flags & zero) == zero)
		padding_char = '0';
	if ((conv_specs.flags & minus) != minus)
		print_count += put_n_c(conv_specs.width, 1, padding_char);
	ft_putchar_fd('%', 1);
	print_count++;
	if ((conv_specs.flags & minus) == minus)
		print_count += put_n_c(conv_specs.width, 1, padding_char);
	return (print_count);
}
