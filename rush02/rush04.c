/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:48:11 by okovalch          #+#    #+#             */
/*   Updated: 2017/09/09 20:48:11 by okovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_rush04(int x_size, int y_size, int x_count, int y_count);

void	put_rush_04(int x_size, int y_size)
{
	int x_count;
	int y_count;

	x_count = 0;
	y_count = 0;
	while (x_count < x_size && y_size != 0)
	{
		print_rush04(x_size, y_size, x_count, y_count);
		write(1, "\n", 1);
		++x_count;
	}
}

void	print_rush04(int x_size, int y_size, int x_count, int y_count)
{
	while (y_count < y_size)
	{
		if ((x_count == 0 && y_count == 0) ||
			(x_count + 1 == x_size && y_count + 1 == y_size))
			write(1, "A", 1);
		else if ((x_count == 0 && y_count + 1 == y_size) ||
			(x_count + 1 == x_size && y_count == 0))
			write(1, "C", 1);
		else
		{
			if (y_count == 0 || y_count + 1 == y_size ||
				x_count == 0 || x_count + 1 == x_size)
				write(1, "B", 1);
			else
				write(1, " ", 1);
		}
		++y_count;
	}
}
