/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:05:50 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/31 20:13:58 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	current_pid = 0;
	static int		i = 7;
	static char		c = 0;

	(void)context;
	(current_pid != info->si_pid) && (current_pid = info->si_pid, c = 0, i = 7);
	if (sig == SIGUSR1)
		c |= (0 << i);
	else if (sig == SIGUSR2)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		if (c == '\0')
			if (kill(current_pid, SIGUSR1) == -1)
				exit(1);
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
	return (0);
}
