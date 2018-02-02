/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:06:12 by cfranco           #+#    #+#             */
/*   Updated: 2018/01/31 23:16:31 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# define BUF_SIZE 		1000000000
# define BUF_SIZE_INPUT 4096

void			ft_putchar(char c);
void			ft_putstr(char *str);
int 			test_characters(char *buf, int *data, int c);
char			*read_files(int argc, char **argv);
int				ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

#endif
