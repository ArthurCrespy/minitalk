/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:29:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/02 15:54:52 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_message_status = 1;

int	check_pid(int argc, char **argv)
{
	if (argc < 3 || argc > 3)
	{
		write(1, "> Error: wrong number of arguments", 33);
		return (1);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		write(1, "> Error: invalid PID", 20);
		return (1);
	}
	return (0);
}

void	receive_confirmation(int sig, siginfo_t *siginfo, void *content)
{
	(void) content;
	(void) siginfo;
	if (sig == SIGUSR2)
	{
		g_message_status = 0;
		write(1, "> OK: Message sent\n", 18);
	}
}

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(500);
		kill(pid, SIGUSR2);
		i++;
	}
}

void	send_bits(int pid, char *str)
{
	int		i;
	int		len;
	int		bit;
	char	c;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		c = str[i];
		bit = 0;
		while (bit < 8)
		{
			usleep(500);
			if ((c & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
		}
		i++;
	}
	send_null(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	sig.sa_sigaction = receive_confirmation;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sig, NULL);
	if (check_pid(argc, argv))
		return (0);
	send_bits(ft_atoi(argv[1]), argv[2]);
	sleep(1);
	if (g_message_status)
		write(1, "> Error: Message not sent\n", 25);
	return (0);
}
