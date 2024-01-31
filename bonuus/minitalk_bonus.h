/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:06:17 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/31 15:25:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

void	handler(int sig, siginfo_t *info, void *context);
void	send_binary(char c, pid_t srv_pid);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	error_exit(void);
void	message_error(char *s);
int		is_valid_integer(char *str);
void	handle(int sig);

#endif