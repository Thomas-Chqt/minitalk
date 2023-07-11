/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 21:50:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_pid(void)
{
	ft_printf("PID : %d\n", getpid());
}

void	sigusr_catcher(int sig_num)
{
	static int	sigusr1_count = 0;
	static int	sigusr2_count = 0;

	signal(SIGUSR1, &sigusr_catcher);
	signal(SIGUSR2, &sigusr_catcher);
	if (sig_num == SIGUSR1)
		ft_printf("SIGUSR1 recived ! (%d)\n", sigusr1_count++);
	if (sig_num == SIGUSR2)
		ft_printf("SIGUSR2 recived ! (%d)\n", sigusr2_count++);
}
