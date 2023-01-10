/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:46:45 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/01/10 15:22:40 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <signal.h>

void	ft_putstr(char *str);
void	handle(int signum);
int		ft_atoi(char *s);
void	ft_send(int num, int rem, int pid);
void	send_signal(int n, int pid);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif
