/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:15:09 by damerica          #+#    #+#             */
/*   Updated: 2019/09/10 16:14:37 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *a;
	int i;

	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	a = malloc(sizeof(int) * (max - min));
	if (a == NULL)
		return (NULL);
	while (min != max)
	{
		a[i] = min;
		i++;
		min++;
	}
	return (a);
}
