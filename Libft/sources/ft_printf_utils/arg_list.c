/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:19:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:53:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	arg_list_start(t_arg_list *list)
{
	va_copy(list->ap_current, list->ap_start);
}

void	arg_list_end(t_arg_list *list)
{
	va_end(list->ap_current);
	va_end(list->ap_start);
}

void	move_ap(unsigned int n, t_arg_list *list)
{
	unsigned int	i;

	if (n == 0)
		return ;
	va_end(list->ap_current);
	va_copy(list->ap_current, list->ap_start);
	i = 0;
	while (i++ < (n - 1))
		va_arg(list->ap_current, int);
}

long long	get_arg(unsigned int n, t_arg_list *list)
{
	move_ap(n, list);
	return (va_arg(list->ap_current, long long));
}

unsigned int	get_arg_no_move(unsigned int n, t_arg_list *list)
{
	va_list			save;
	unsigned int	value;

	va_copy(save, list->ap_current);
	value = (unsigned int)get_arg(n, list);
	va_end(list->ap_current);
	va_copy(list->ap_current, save);
	va_end(save);
	return (value);
}
