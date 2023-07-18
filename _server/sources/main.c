/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/18 16:25:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#ifdef MEMCHECK

__attribute__((destructor))
static void	destructor(void)
{
	char	*pid;
	char	*cmd;

	print_report();
	pid = ft_itoa(getpid());
	cmd = ft_strjoin("leaks -q ", pid);
	system((const char *)cmd);
	free(pid);
	free(cmd);
}

#endif // MEMCHECK

int	main(void)
{
	struct sigaction	sa;

	signal(SIGINT, &exit_handler);
	sa.__sigaction_u.__sa_handler = &signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID : %d\n", getpid());
	while (1)
		pause();
}
