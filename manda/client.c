/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:05:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 21:20:14 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(void)
{
	write(1, "pid incorrect\n", 14);
	exit(1);
}

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

int	is_valid_integer(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
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
	str = argv[2];
	while (str[i])
	{
		send_binary(str[i], srv_pid);
		i++;
	}
	return (0);
}
