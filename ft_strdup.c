/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:53:25 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 20:39:50 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	unsigned int	len;
	char			*p;

	len = ft_strlen(src);
	p = malloc((len + 1) * sizeof(char));
	printf("ft_strdup %p\n", p);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}