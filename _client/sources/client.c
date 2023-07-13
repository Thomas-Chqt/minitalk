/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/12 16:37:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_byte(t_uint8 byte, pid_t server_pid)
{
	t_uint8	i;

	i = 0;
	while (i < 8)
	{
		if ((byte >> i) & 1 == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(10000);
		i++;
	}
}