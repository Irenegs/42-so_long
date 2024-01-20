/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:12:10 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/19 21:07:55 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	special_char(char c)
{
	char	*special_chars;

	special_chars = "CEP";
	while (*special_chars)
	{
		if (c == *special_chars)
			return (0);
		special_chars++;
	}
	return (1);
}

int	valid_char(char c)
{
	char	*valid_chars;

	valid_chars = "10CEP\n";
	while (*valid_chars)
	{
		if (c == *valid_chars)
			return (0);
		valid_chars++;
	}
	return (1);
}

int	end_line(char c)
{
	if (c == '\n' || c == '\0')
		return (0);
	return (1);
}
