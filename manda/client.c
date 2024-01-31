/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:05:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/31 20:37:51 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary(char c, pid_t srv_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(srv_pid, SIGUSR1) == -1)
				error_exit();
		}
		else if (((c >> i) & 1) == 1)
		{
			if (kill(srv_pid, SIGUSR2) == -1)
				error_exit();
		}
		i--;
		usleep(300);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	srv_pid;
	char	*str;
	int		i;

	i = 0;
	if (argc != 3 || !is_valid_integer(argv[1]))
	{
		write(1, "incorrect argument\n", 19);
		return (0);
	}
	srv_pid = ft_atoi(argv[1]);
	if (srv_pid == 1 || srv_pid == 0)
		message_error("incorrect pid");
	str = argv[2];
	while (str[i])
	{
		send_binary(str[i], srv_pid);
		i++;
	}
	return (0);
}
