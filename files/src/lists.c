/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:28:53 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/02 15:52:20 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	clear_list(t_struct *message)
{
	t_struct	*tmp;

	while (message != NULL)
	{
		tmp = message;
		message = message->next;
		free(tmp);
	}
}

void	print_list(t_struct *message)
{
	t_struct	*tmp;

	tmp = message;
	while (tmp != NULL)
	{
		ft_putchar_fd(tmp->data, 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}
