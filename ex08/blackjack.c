/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:25:27 by osabir            #+#    #+#             */
/*   Updated: 2023/04/02 13:52:38 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	aces;

	if (ac == 2)
	{
		i = 0;
		j = 0;
		aces = 0;
		while (av[1][i])
		{
			if (av[1][i] == 'A')
			{
				j += 11;
				aces++;
			}
			else if (av[1][i] == 'T' || av[1][i] == 'J' \
				|| av[1][i] == 'D' || av[1][i] == 'K')
				j += 10;
			else if (av[1][i] >= '2' && av[1][i] <= '9')
			{
				j += (av[1][i] - 48);
			}
			else
			{
				printf("ERROR\n");
				exit(1);
			}
			i++;
		}
		while (j > 21 && aces > 0)
		{
			j -= 10;
			aces--;
		}
		if (j == 21)
			printf("Blackjack!\n");
		else
			printf("%d\n", j);
	}
	return (0);
}
