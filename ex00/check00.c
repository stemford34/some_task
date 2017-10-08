/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 14:53:21 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/08/27 14:54:22 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check00(int x, int y, char *src);
int		correct00(int i, int j, char input);

int g_x;
int g_y;

int		check00(int x, int y, char *src)
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
			if (correct00(i, j, src[t++]) == 0)
				return (0);
			i++;
		}
		j++;
		i = 1;
	}
	return (1);
}

int		correct00(int i, int j, char input)
{
	if ((j == 1) || (j == g_y))
	{
		if (((i == 1) || (i == g_x)) && (input == 'o'))
			return (1);
		else if (input == '-')
			return (1);
	}
	else
	{
		if (((i == 1) || (i == g_x)) && (input == '|'))
			return (1);
		else if (input == ' ')
			return (1);
	}
	return (0);
}
