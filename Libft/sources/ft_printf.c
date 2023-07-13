/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:44:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:54:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf(const char *format, ...)
{
	t_arg_list	args;
	size_t		i;
	size_t		print_count;

	va_start(args.ap_start, format);
	arg_list_start(&args);
	print_count = 0;
	i = 0;
	while (format != NULL && format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			print_count++;
			i++;
		}
		else if (format[i] == '%')
		{
			i++;
			if (print_converted(format, &i, &args, &print_count) < 0)
				return (-1);
		}
	}
	return (print_count);
}
