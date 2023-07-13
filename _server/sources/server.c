/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/13 18:10:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int sig)
{
	static t_uint8	byte = 0;
	static t_uint8	i;

	if (sig == SIGUSR1)
		byte = (byte | (1 << i++));
	if (sig == SIGUSR2)
		i++;
	if (i < 8)
		return ;
	ft_putchar_fd(byte, 1);
	i = 0;
	byte = 0;
}
