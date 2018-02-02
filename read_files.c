/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:22:40 by cfranco           #+#    #+#             */
/*   Updated: 2018/01/29 15:22:44 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		test_characters(char *buf, int *data, int c)
{
	int		line_length;
	int		lltest;
	int		line_c;

	line_length = 0;
	lltest = 0;
	line_c = 0;
	while (buf[++c - 1] != EOF)
	{
		if (buf[c - 1] == '\n')
		{
			if (lltest == 0)
				lltest = line_length;
			else if (line_length != lltest)
				return (0);
			line_length = 0;
			line_c++;
		}
		else if (buf[c - 1] != data[1] && buf[c - 1] != data[2])
			return (0);
		line_length++;
	}
	if (data[0] != (line_c - 1))
		return (0);
	return (1);
}