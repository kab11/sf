/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:44:49 by kblack            #+#    #+#             */
/*   Updated: 2018/01/28 18:56:21 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	char buf[] = "A\n";
	printf("%s", buf);

	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == 'A')
			printf("%c", 'A');
		if (buf[i] == '\n')
			y++;
		i++;
	}
	x = (i / y) - 1;
	return (0);
}
