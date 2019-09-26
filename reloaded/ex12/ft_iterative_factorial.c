/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:14:28 by damerica          #+#    #+#             */
/*   Updated: 2019/09/03 14:40:36 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int a;
	int result;

	a = 1;
	result = 1;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 1 || nb > 12)
	{
		return (0);
	}
	while (a <= nb)
	{
		result = result * a;
		a++;
	}
	return (result);
}
