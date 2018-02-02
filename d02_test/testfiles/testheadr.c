/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testheadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:21:23 by kblack            #+#    #+#             */
/*   Updated: 2018/01/11 10:04:09 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(0);
}

int ft_nputchar(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return(0);
}

int main()
{
	ft_nputchar('@', 42);
	ft_putchar('\n');
	return (0);
}
