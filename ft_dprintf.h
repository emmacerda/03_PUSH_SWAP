/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 18:22:29 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/08 18:23:21 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

int	ft_dprintf(int fd, const char *str, ...);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_puthex(unsigned int n, int fd);
int	ft_puthex_upp(unsigned int n, int fd);
int	ft_count_hex(unsigned int n);
int	ft_putnbr_unsigned(unsigned int n, int fd);
int	ft_print_42(void);
#endif
