/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:52:26 by kblack            #+#    #+#             */
/*   Updated: 2018/01/14 21:33:31 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putline(char start, char end, char fill, int length)
{
	ft_putchar(start);
	while (length > 2)
	{
		ft_putchar(fill);
		length -= 1;
	}
	if (length == 2)
	{
		ft_putchar(end);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int len;

	if (x <= 0 || y <= 0)
	{
		return ;
	}
	else
	{
		ft_putline('o', 'o', '-', x);
		len = y;
		if (x > 2)
		{
			while (len > 2)
			{
				ft_putline('|', '|', ' ', x);
				len--;
			}
			ft_putline('o', 'o', '-', x);
		}
	}
}
