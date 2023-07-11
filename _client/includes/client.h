/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 21:28:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# ifdef MEMCHECK
#  include <memory_leak_detector.h>
# endif // MEMCHECK

# define SIGKILL 9
# define SIGUSR1 30
# define SIGUSR2 31

typedef int				t_pid;
typedef unsigned int	t_useconds;

# include <libft.h>

void	free(void *);
int		kill(t_pid pid, int sig);
int		usleep(t_useconds microseconds);

void	kill_server(t_pid pid);
void	send_signal(t_pid pid, int signal);

#endif // CLIENT_H