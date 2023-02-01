/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:29:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/01 14:35:35 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	null_kill(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(100);
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
			usleep(100);
			if ((c & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
		}
		i++;
	}
	null_kill(pid);
}

void	receive_confirmation(int sig, siginfo_t *siginfo, void *content)
{
	(void) content;
	(void) siginfo;
	if (sig == SIGUSR1)
		write(1, "> OK: Message sent\n", 18);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	sig.sa_sigaction = receive_confirmation;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	if (argc < 3 || argc > 3)
	{
		write(1, "> Error: wrong number of arguments", 33);
		return (1);
	}
	send_bits(ft_atoi(argv[1]), argv[2]);
	while (1)
		;
	return (0);
}
