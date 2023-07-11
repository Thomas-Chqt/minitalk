/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 20:28:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	kill_server(t_pid pid)
{
	kill(pid, SIGKILL);
}

void	send_signal(t_pid pid, int signal)
{
	kill(pid, signal);
}