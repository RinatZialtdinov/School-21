/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:06:18 by damerica          #+#    #+#             */
/*   Updated: 2019/09/19 15:15:21 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newstr;
	int		i;
	int		i1;
	int		i2;

	if (!s)
		return (NULL);
	i2 = 0;
	i1 = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i1 + 1] != '\0')
		i1++;
	if (i1 + 1 == i)
		return (newstr = (char *)malloc(sizeof(char) * (0)));
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1--;
	if (!(i || i1))
		return ((char *)s);
	if (!(newstr = (char *)malloc(sizeof(char) * (i1 - i + 2))))
		return (NULL);
	return (ft_write_str(newstr, s, i, i1));
}
