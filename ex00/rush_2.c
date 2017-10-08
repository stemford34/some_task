/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:45:20 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/09/09 14:45:20 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		check00(int x, int y, char *src);
int		check01(int x, int y, char *src);
int		check02(int x, int y, char *src);
int		check03(int x, int y, char *src);
int		check04(int x, int y, char *src);
void	writer(char *n);
void	ft_putstr(char *str);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
int		block_len(char *src);
int		block_rows(char *src);
int		check_r(int x, int y, char *src);
int		check_sq(int x, int y, char *src);

int		g_len_x;
int		g_len_y;
int		g_write_flag;

char	*no_newline(char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(1);
	while (src[i] != '\0')
	{
		if (src[i] != '\n')
			str[j++] = src[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	checker(char *no_src)
{
	if (check00(g_len_x, g_len_y, no_src) == 1)
		writer("rush-00");
	if (check01(g_len_x, g_len_y, no_src) == 1)
		writer("rush-01");
	if (check02(g_len_x, g_len_y, no_src) == 1)
		writer("rush-02");
	if (check03(g_len_x, g_len_y, no_src) == 1)
		writer("rush-03");
	if (check04(g_len_x, g_len_y, no_src) == 1)
		writer("rush-04");
	if (check_r(g_len_x, g_len_y, no_src) == 1)
		writer("rectangle");
	if (check_sq(g_len_x, g_len_y, no_src) == 1)
		writer("square");
	if (g_write_flag == 1)
		ft_putstr("\n");
	else
		ft_putstr("aucune\n");
}

void	writer(char *n)
{
	if (g_write_flag == 1)
		ft_putstr(" || [");
	else
	{
		ft_putstr("[");
		g_write_flag = 1;
	}
	ft_putstr(n);
	ft_putstr("] [");
	ft_putnbr(g_len_x);
	ft_putstr("] [");
	ft_putnbr(g_len_y);
	ft_putstr("]");
}

int		main(void)
{
	int		i;
	char	buf[2];
	char	*mem;
	int		ret;

	i = 0;
	g_write_flag = 0;
	mem = malloc(1);
	while ((ret = read(0, buf, 1)))
		mem[i++] = buf[0];
	mem[i] = '\0';
	g_len_x = block_len(mem);
	g_len_y = block_rows(mem);
	checker(no_newline(mem));
	return (0);
}
