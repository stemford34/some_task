/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:45:24 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/09/10 19:45:25 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_r(int x, int y, char *src);
int		correct_r(int i, int j, char input);

int g_x;
int g_y;

int		check_r(int x, int y, char *src)
{
	int i;
	int j;
	int t;

	i = 1;
	j = 1;
	t = 0;
	g_x = x;
	g_y = y;
	if ((x < 3) || (y < 3))
		return (0);
	while (j <= y)
	{
		while (i <= x)
		{
			if (correct_r(i, j, src[t++]) == 0)
				return (0);
			i++;
		}
		j++;
		i = 1;
	}
	return (1);
}

int		correct_r(int i, int j, char input)
{
	if (((i == 1) || (j == 1) || (i == g_x) || (j == g_y)) && (input != ' '))
			return (1);
	else if (input == ' ')
		return (1);
	return (0);
}
