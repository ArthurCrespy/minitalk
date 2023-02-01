/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:29:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/01 09:25:40 by acrespy          ###   ########.fr       */
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
			if ((c & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3 || argc > 3)
	{
		write(1, "Error: wrong number of arguments", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_bits(pid, argv[2]);
	return (0);
}
