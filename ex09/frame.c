/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:43:53 by osabir            #+#    #+#             */
/*   Updated: 2023/04/03 11:53:24 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int g_loble;

void	ft_frame(char *s)
{
	int	i;

	if (s[0] != '\0')
	{
		i = 0;
		if (s[i] != ' ')
		{
			printf("* ");
			while (s[i] != ' ' && s[i] != '\0')
			{
				printf("%c", s[i]);
				i++;
			}
			printf(" *\n");
		}
		while (s[i])
		{
			if (s[i] == ' ' && s[i + 1] != ' ')
			{
				i++;
				if (s[i] != '\0')
				{
					printf("* ");
					while (s[i] != ' ' && s[i] != '\0')
					{
						printf("%c", s[i]);
						i++;
					}
					printf(" *\n");
				}
			}
			else
				i++;
		}
	}
}

void	long_word(char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		if (!isspace(s[i]))
		{
			j = 0;
			while (!isspace(s[i + j]) && s[i + j] != '\0')
				j++;
			if (g_loble < j)
				g_loble = j + 4;
			i += j;
		}
		else
			i++;
	}
}

void	print(void)
{
	int	j;

	j = 0;
	while (j < g_loble)
	{
		printf("*");
		j++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac >= 2)
	{
		while (av[i])
			long_word(av[i++], ' ');
		print();
		i = 1;
		while (av[i])
			ft_frame(av[i++]);
		print();
	}
	return (0);
}
