/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:34:08 by damerica          #+#    #+#             */
/*   Updated: 2019/09/18 21:37:35 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t n)
{
	char	*str1;
	char	*str2;
	int		i;
	int		n1;

	str1 = (char *)dest;
	str2 = (char *)source;
	n1 = (int)n;
	i = 0;
	while (i < n1 && str2[i - 1] != '\200')
	{
		str1[i] = str2[i];
		i++;
		if (ch == str2[i - 1])
			return (str1 + i);
	}
	return (NULL);
}
