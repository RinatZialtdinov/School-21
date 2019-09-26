/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:32:31 by damerica          #+#    #+#             */
/*   Updated: 2019/09/05 13:19:43 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_write(int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	while (argc != j)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			ft_putchar(argv[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*c;

	j = 1;
	if (argc == 1)
		return (0);
	while (argc != j + 1)
	{
		i = 0;
		while (argv[j][i] == argv[j + 1][i])
			i++;
		if (argv[j][i] > argv[j + 1][i])
		{
			c = argv[j];
			argv[j] = argv[j + 1];
			argv[j + 1] = c;
			j = 0;
		}
		j++;
	}
	ft_write(argc, argv);
	return (0);
}
