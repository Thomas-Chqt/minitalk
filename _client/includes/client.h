/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/13 17:35:34 by tchoquet         ###   ########.fr       */
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

void	send_str(pid_t server_pid, const char *str);

#endif // CLIENT_H