/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:21:43 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/08/27 20:21:49 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check04(int x, int y, char *src);
int	correct04a(int i, int j, char input);
int	correct04b(int i, int j, char input);

int g_x;
int g_y;

int	check04(int x, int y, char *src)
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
			if ((correct04a(i, j, src[t]) == 0) &&
			(correct04b(i, j, src[t]) == 0))
				return (0);
			i++;
			t++;
		}
		j++;
		i = 1;
	}
	return (1);
}

int	correct04a(int i, int j, char input)
{
	if (j == 1)
	{
		if (((i != 1) && (i != g_x)) && (input == 'B'))
			return (1);
		else if ((i == 1) && (input == 'A'))
			return (1);
		else if (input == 'C')
			return (1);
	}
	if ((j > 1) && (j < g_y))
	{
		if (((i == 1) || (i == g_x)) && (input == 'B'))
			return (1);
		else if (input == ' ')
			return (1);
	}
	return (0);
}

int	correct04b(int i, int j, char input)
{
	if ((j > 1) && (j == g_y))
	{
		if (((i != 1) && (i != g_x)) && (input == 'B'))
			return (1);
		else if ((i == 1) && (input == 'C'))
			return (1);
		else if (input == 'A')
			return (1);
	}
	return (0);
}
