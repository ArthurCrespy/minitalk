/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:28:53 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/02 15:52:20 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_confirmation(siginfo_t *siginfo)
{
	kill(siginfo->si_pid, SIGUSR2);
}

void	store_char(char c, t_struct **message)
{
	t_struct	*new;
	t_struct	*tmp;

	new = malloc(sizeof(t_struct));
	if (!new)
		clear_list(*message);
	new->data = c;
	new->next = NULL;
	if (*message == NULL)
		*message = new;
	else
	{
		tmp = *message;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	receive_bits(int sig, siginfo_t *siginfo, void *context)
{
	static char			c;
	static int			bit;
	static t_struct		*message = NULL;

	(void) context;
	(void) siginfo;
	if (sig == SIGUSR1)
		c = c | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			print_list(message);
			send_confirmation(siginfo);
			clear_list(message);
			message = NULL;
		}
		store_char(c, &message);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = receive_bits;
	sig.sa_flags = SA_SIGINFO;
	write(1, "> PID: ", 7);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		;
	return (0);
}
