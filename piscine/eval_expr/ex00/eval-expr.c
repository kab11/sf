/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval-expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:23:01 by kblack            #+#    #+#             */
/*   Updated: 2018/01/27 23:26:31 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int eval_expr(char *str)
{

}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar(’\n’);
	}
	return (0);
}
