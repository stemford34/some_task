/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 10:51:01 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/08/27 10:51:06 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check03(int x, int y, char *src);
int	correct03(int i, int j, char input);

int g_x;
int g_y;

int	check03(int x, int y, char *src)
{
	int i;
	int j;
	int t;

	i = 1;
	j = 1;
	t = 0;
	g_x = x;
	g_y = y;
	if (x == 0)
		return (0);
	while (j <= y)
	{
		while (i <= x)
		{
			if (correct03(i, j, src[t++]) == 0)
				return (0);
			i++;
		}
		i = 1;
		j++;
	}
	return (1);
}

int	correct03(int i, int j, char input)
{
	if ((((j == 1) && (i == 1)) || ((j == g_y) && (i == 1))) && (input == 'A'))
		return (1);
	else if ((((j == 1) && (i == g_x)) ||
	((j == g_y) && (i == g_x))) && (input == 'C'))
		return (1);
	else if ((((j == 1) || (j == g_y)) && ((i != 1) ||
	(i != g_x))) && (input == 'B'))
		return (1);
	else if ((((j != 1) && (i == 1)) ||
	((j != 1) && (i == g_x))) && (input == 'B'))
		return (1);
	else if (((j >= 2) && (i >= 2)) && (input == ' '))
		return (1);
	return (0);
}
