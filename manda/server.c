/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:05:50 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/31 20:37:44 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	updatepid(char *c, int *i, int *client_pid, int *current_pid)
{
	*c = 0;
	*i = 7;
	*client_pid = *current_pid;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	current_pid = 0;
	static pid_t	client_pid = 0;
	static int		i = 7;
	static char		c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
		updatepid(&c, &i, &client_pid, &current_pid);
	if (sig == SIGUSR1)
		c |= (0 << i);
	else if (sig == SIGUSR2)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("server pid : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
