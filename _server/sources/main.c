/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/12 16:25:07 by tchoquet         ###   ########.fr       */
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
	// system((const char *)cmd);
	free(pid);
	free(cmd);
}

#endif // MEMCHECK

int main()
{
	struct sigaction	sa_usr1;
	struct sigaction	sa_usr2;

	sa_usr1.__sigaction_u.__sa_sigaction = &signal_handler;
	sa_usr2.__sigaction_u.__sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa_usr1, NULL);
	sigaction(SIGUSR2, &sa_usr2, NULL);
	signal(SIGINT, &sigint_handler);
	print_pid();
	while (1)
		pause();
}