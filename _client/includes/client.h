/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/18 16:51:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# ifdef MEMCHECK
#  include <memory_leak_detector.h>
# endif // MEMCHECK

# include <signal.h>
# include <libft.h>

typedef unsigned int	t_useconds;

void	free(void *ptr);
int		usleep(t_useconds microseconds);
void	exit(int exit_code);

void	send_str(pid_t server_pid, const char *str);

#endif // CLIENT_H