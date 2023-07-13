/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/13 03:07:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_pid(void)
{
	ft_printf("PID : %d\n", getpid());
}

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static t_uint8	byte = 0;
	static t_uint8	i;

	if (sig == SIGUSR1)
		byte = (byte | (1 << i++));
	if (sig == SIGUSR2)
		i++;
	if (i < 8)
		return ;
	ft_printf("%X\n", byte);
	i = 0;
	byte = 0;
}

void	sigint_handler(int sig)
{
	exit(0);
}
