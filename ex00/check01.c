/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:12:20 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/08/27 16:13:56 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check01(int x, int y, char *src);
int	correct01(int i, int j, char input);

int g_x;
int g_y;

int	check01(int x, int y, char *src)
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
			if (correct01(i, j, src[t++]) == 0)
				return (0);
			i++;
		}
		j++;
		i = 1;
	}
	return (1);
}

int	correct01(int i, int j, char input)
{
	if ((j == 1) || (j == g_y))
	{
		if (((j == 1) && (i == 1)) && (input == '/'))
			return (1);
		if (((j == 1) && (i != 1) && (i == g_x)) && (input == '\\'))
			return (1);
		if (((j == g_y) && (j > 1) && (i == 1)) && (input == '\\'))
			return (1);
		if (((j == g_y) && (i != 1) &&
			(i == g_x) && (j != 1)) && (input == '/'))
			return (1);
		if (((i > 1) && (i < g_x)) && (input == '*'))
			return (1);
	}
	if ((j > 1) && (j < g_y))
	{
		if (((i != 1) && (i != g_x)) && (input == ' '))
			return (1);
		else if (input == '*')
			return (1);
	}
	return (0);
}
