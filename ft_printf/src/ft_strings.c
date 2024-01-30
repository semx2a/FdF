/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:24:31 by seozcan           #+#    #+#             */
/*   Updated: 2024/01/30 14:46:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <string.h>

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i] != 0)
			ft_putchar_printf(s[i]);
	else
		i = ft_putstr_printf("(null)");
	return (i);
}

size_t	ft_strlen_printf(const char *str)
{
	size_t	len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	return (len);
}

char	*ft_strchr_printf(const char *s, int c)
{
	int		i;
	char	a;

	i = -1;
	a = c;
	while (s[++i])
		if (s[i] == a || (s[i] == '\0' && a == 0))
			return ((char *)s + i);
	return (0);
}
