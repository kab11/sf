/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:09:23 by cfranco           #+#    #+#             */
/*   Updated: 2018/01/16 21:09:25 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned	int c1;
	unsigned	int c2;
	unsigned	int c3;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	while (dest[c1] != '\0')
		c1++;
	while (src[c3] != '\0')
		c3++;
	if (c1 <= size)
	{
		while (src[c2] != '\0' && c2 < (size - c1 - 1))
		{
			dest[c2 + c1] = src[c2];
			c2++;
		}
	}
	if (size != 0 && c1 <= size)
		dest[c1 + c2] = '\0';
	if (c1 > size)
		return (size + c3);
	else
		return (c1 + c3);
}
