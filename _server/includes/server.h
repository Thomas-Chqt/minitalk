/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/13 17:34:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifdef MEMCHECK
#  include <memory_leak_detector.h>
# endif // MEMCHECK

# include <signal.h>
# include <libft.h>

pid_t	getpid(void);
int		pause(void);

void	signal_handler(int sig, siginfo_t *info, void *ucontext);

#endif // SERVER_H