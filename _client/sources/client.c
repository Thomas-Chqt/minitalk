/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/18 16:47:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_str(pid_t server_pid, const char *str)
{
	t_uint64	s_i;
	t_uint8		b_i;

	s_i = 0;
	while (str[s_i] != 0)
	{
		b_i = 0;
		while (b_i < 8)
		{
			if (((str[s_i] >> b_i++) & 1) == 1)
			{
				if (kill(server_pid, SIGUSR1) != 0)
					exit(2);
			}
			else
			{
				if (kill(server_pid, SIGUSR2) != 0)
					exit(2);
			}
			usleep(100);
		}
		s_i++;
	}
}
