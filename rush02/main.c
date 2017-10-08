/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:39:00 by okovalch          #+#    #+#             */
/*   Updated: 2017/09/09 17:39:00 by okovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_rush_00(int x_size, int y_size);
void	put_rush_01(int x_size, int y_size);
void	put_rush_02(int x_size, int y_size);
void	put_rush_03(int x_size, int y_size);
void	put_rush_04(int x_size, int y_size);

int		main(void)
{
	int x;
	int y;

	x = 1;
	y = 1;
	put_rush_00(x, y);
	put_rush_01(x, y);
	put_rush_02(x, y);
	put_rush_03(x, y);
	put_rush_04(x, y);
	return (0);
}

	int i = 0;
	char buf[2];
	char *mem;
	int ret;

	mem = malloc(1);
	while ((ret = read(0, buf, 1)))
		mem[i++] = buf[0];
	mem[i] = '\0';