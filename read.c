/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:37:35 by kblack            #+#    #+#             */
/*   Updated: 2018/01/31 23:37:38 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
