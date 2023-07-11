/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 22:01:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#ifdef MEMCHECK

# include <memory_leak_detector.h>

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

int	main(int argc, char const *argv[])
{
	t_pid		pid;

	if (argc < 2)
		return (-1);
	pid = (t_pid)ft_atoi(argv[1]);
	for (size_t i = 0; i < 2; i++)
	{
		if (i % 2 == 0)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);		
		usleep(100);
	}
	send_signal(pid, SIGKILL);
	return (0);
}
