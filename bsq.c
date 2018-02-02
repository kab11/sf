/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:05:55 by cfranco           #+#    #+#             */
/*   Updated: 2018/01/31 23:31:16 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	read_file(char *buf, int fd)
{
	int		ret;
	char	ibuf[BUF_SIZE_INPUT];
	int		store;

	store = 0;
	ret = 1;
	if (!fd)
	{
		while (ret)
		{
			ret = read(fd, ibuf, BUF_SIZE_INPUT);
			ibuf[ret] = '\0';
			ft_strlcat(buf, ibuf, BUF_SIZE);
			store += ret;
		}
		buf[store] = -1;
	}
	else
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = -1;
	}
}

int		*get_data(char *buf)
{
	int		c;
	int		*data;
	int		num;

	num = 0;
	c = 0;
	data = (int*)malloc(sizeof(int) * 4);
	while (buf[c] <= '9' && buf[c] >= '0')
	{
		num = (num * 10) + (buf[c] - '0');
		c++;
	}
	data[0] = num;
	data[1] = buf[c++];
	data[2] = buf[c++];
	data[3] = buf[c];
	return (data);
}

int		check_input(char *buf, int fd)
{
	int		c;
	int		*data;

	c = 0;
	read_file(buf, fd);
	if (buf[0] > '9' || buf[0] < '0')
		return (0);
	data = get_data(buf);
	while (buf[++c] != '\n')
		if (buf[c] > 126 && buf[c] < 32)
			return (0);
	if (c < 4)
		return (0);
	if (!test_characters(buf, data, c))
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		min_num(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	proccess_first(char *buf, int *data, int *sumv, int *max_pos, int c)
{
	int c2;
	int max_num;
	int last_sum;
	int last_sum_b;
	int c3;

	c2 = -1;
	max_num = 0;
	last_sum = 0;
	last_sum_b = 0;
	c3 = 0;
	while (++c2 < data[0])
	{
		while (buf[++c] != '\n')
		{
			last_sum_b = last_sum;
			last_sum = sumv[c3];
			if (buf[c] == data[1] && (buf[c - 1] == '\n' || c2 == 0))
				sumv[c3] = 1;
			else if (buf[c] == data[1])
				sumv[c3] = min_num(last_sum, min_num(last_sum_b, sumv[c3 - 1])) + 1;
			else if (buf[c] == data[2])
				sumv[c3] = 0;
			if (sumv[c3] > max_num)
			{
				max_num = sumv[c3];
				max_pos[0] = c3;
				max_pos[1] = c2;
				max_pos[2] = max_num;
			}
			c3++;
		}
		last_sum_b = 0;
		last_sum = 0;
		c3 = 0;
	}
}

int		*calc_square(char *buf)
{
	int c;
	int c2;
	int length;
	int *sumv;
	int *max_pos;

	c = 0;
	c2 = 0;
	length = 0;
	max_pos = (int*)malloc(sizeof(int) * 3);
	while (buf[c] != '\n')
		c++;
	c2 = c;
	while (buf[++c2] != '\n')
		length++;
	sumv = (int*)malloc(sizeof(int) * length);
	proccess_first(buf, get_data(buf), sumv, max_pos, c);
	free(sumv);
	return (max_pos);
}

void	print_square(char *buf, int *data)
{
	int c;
	int c2;
	int c3;
	int *buff_data;

	c = 0;
	c2 = 0;
	c3 = 0;
	buff_data = get_data(buf);
	while (buf[c] != '\n')
		c++;
	c2 = -1;
	while (++c2 < buff_data[0])
	{
		while (buf[++c] != '\n')
		{
			if (c3 > (data[0] - data[2]) && c3 <= data[0] &&
				c2 <= data[1] && c2 > (data[1] - data[2]))
				buf[c] = buff_data[3];
			c3++;
		}
		c3 = 0;
	}
	buf[c] = '\0';
}

int		main(int argc, char **argv)
{
	int		fd;
	int		c;
	char	*buf;
	int		*rec_pos;

	c = 0;
	rec_pos = NULL;
	buf = (char*)malloc(sizeof(char) * BUF_SIZE);
	buf[0] = '\0';
	if (argc == 1)
	{
		if (!check_input(buf, 0))
			write(2, "map error", ft_strlen("map error"));
		else
		{
			rec_pos = calc_square(buf);
			ft_putchar('\n');
			print_square(buf, rec_pos);
			ft_putstr(buf);
		}
	}
	else
	{
		c = 1;
		while (c < argc)
		{
			fd = open(argv[c], O_RDONLY);
			if (fd == -1 || !check_input(buf, fd))
				write(2, "map error", ft_strlen("map error"));
			else
			{
				rec_pos = calc_square(buf);
				print_square(buf, rec_pos);
				ft_putstr(buf);
			}
			c++;
			free(rec_pos);
		}
	}
	free(buf);
	return (0);
}
