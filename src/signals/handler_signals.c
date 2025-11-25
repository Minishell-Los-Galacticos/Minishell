/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 02:47:09 by migarrid          #+#    #+#             */
/*   Updated: 2025/11/25 17:13:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
 * Maneja Ctrl+C en modo interactivo: marca la señal
 * recibida para ser procesada posteriormente
*/

# if defined MAIN || defined MSTEST
void	handle_sigint_interative(int sig)
{
	(void)sig;
	write(1, "^C", 2);
	g_signal = SIGINT;
}
# endif

# ifdef CORRECTION
void	handle_sigint_interative(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_signal = SIGINT;
}
# endif

/*
 * Maneja Ctrl+C en heredoc: marca la señal y escribe
 * un salto de línea para limpiar la entrada
*/

# if defined MAIN || defined MSTEST
void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	write(1, "^C", 2);
	g_signal = SIGINT;
}
# endif

# ifdef CORRECTION
void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	g_signal = SIGINT;
	rl_done = TRUE;
}
# endif
