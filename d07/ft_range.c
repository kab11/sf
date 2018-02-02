/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 23:43:20 by kblack            #+#    #+#             */
/*   Updated: 2018/01/18 23:43:30 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int		count;
	int		*str;
	
	count = 0;
	str = (int*)malloc(sizeof(int) * (max -min));
	
	if (min >= max)
	{
		return (0);
	}
	while (min < max)
	{
		str[count] = min;	
		min++;
		count++;
	}
	str[count] = '\0';
	return (str);
}
