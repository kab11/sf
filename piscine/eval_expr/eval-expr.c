/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval-expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:23:01 by kblack            #+#    #+#             */
/*   Updated: 2018/01/28 13:09:30 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_factor();
int ft_product();
int ft_sum();

char * ptr;

//_____ SUM 
int ft_sum()
{
	int product1 = ft_product();
	while (*ptr == '+')
	{
		++ptr;
		int product2 = ft_product();
		product1 = product1 + product2;
	}
	return (product1);
}

//__ __ PRODUCT
int ft_product()
{
	int factor1 = ft_factor();
	//multiply factors 
	while (*ptr == '*')
	{
		++ptr;
		int factor2 = ft_factor();
		factor1 = factor1 * factor2;
	}
	return (factor1);
}

//_ _ _  FACTOR
//function that detects if its a digit 
int ft_factor()
{
	//check if char is a valid digit
	if(*ptr >= '0' && *ptr <= '9')
		return *ptr++ - '0';
	else
		printf("Not a valid number.");
	return (0);
}

int main()
{
	ptr = "2*3+4*5";
	int result = ft_sum();
	return(0);
}

/*int eval_expr(char *str)
int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar(’\n’);
	}
	return (0);
}*/
