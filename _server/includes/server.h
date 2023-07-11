/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:30:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/11 21:50:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifdef MEMCHECK
#  include <memory_leak_detector.h>
# endif // MEMCHECK

# define SIGKILL 9
# define SIGUSR1 30
# define SIGUSR2 31

typedef int	t_pid;

# include <libft.h>

t_pid	getpid(void);
void	(*signal(int, void (*)(int)))(int);
int		pause(void);

void	print_pid(void);
void	sigusr_catcher(int sig_num);

#endif // SERVER_H