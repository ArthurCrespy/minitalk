/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:28:33 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/01 08:28:44 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
long	ft_atoi(const char *str);

#endif
