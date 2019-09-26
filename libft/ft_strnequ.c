/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:38:34 by damerica          #+#    #+#             */
/*   Updated: 2019/09/18 21:05:52 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (!s1 || !s2 || !n)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && n != 0)
	{
		i++;
		n--;
	}
	if (s1[i] == s2[i] || n == 0)
		return (1);
	else
		return (0);
}