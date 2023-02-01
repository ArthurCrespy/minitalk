/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:28:53 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/01 08:29:03 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_confirmation(siginfo_t *siginfo)
{
	kill(siginfo->si_pid, SIGUSR1);
}

void	receive_bits(int sig, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	bit;

	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, recieve_bits);
	signal(SIGUSR2, recieve_bits);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
