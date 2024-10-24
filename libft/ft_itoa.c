/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:37:10 by moouahab          #+#    #+#             */
/*   Updated: 2023/10/28 20:37:10 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	digit;

	digit = 0;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	ft_convert(int n, char *str, int count_d)
{
	while (n > 0)
	{
		str[--count_d] = '0' + n % 10;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		count_d;
	char	*str;

	count_d = ft_count_digit(n) + (n <= 0);
	if (n == 0)
	{
		str = malloc(sizeof(char ) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = ft_calloc(count_d + 1, 1);
	if (!str)
		return (NULL);
	str[count_d] = '\0';
	if (n < 0)
	{
		*str = '-';
		str[--count_d] = -(n % 10) + '0';
		n = -(n / 10);
	}
	ft_convert(n, str, count_d);
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    	// Cas de base
	int num1 = 12345;
    	char *str1 = ft_itoa(num1);
	printf("Numéro : %d, Chaîne : %s\n", num1, str1);
	free(str1);

	// Cas de base avec un nombre négatif
	int num2 = -6789;
	char *str2 = ft_itoa(num2);
	printf("Numéro : %d, Chaîne : %s\n", num2, str2);
	free(str2);

    	// Cas de base avec zéro
    	int num3 = 0;
    	char *str3 = ft_itoa(num3);
    	printf("Numéro : %d, Chaîne : %s\n", num3, str3);
    	free(str3);

    	// Cas de INT_MIN (limite inférieure)
    	int num4 = INT_MIN;
    	char *str4 = ft_itoa(num4);
    	printf("Numéro : %d, Chaîne : %s\n", num4, str4);
    	free(str4);
    	return 0;
}
*/
