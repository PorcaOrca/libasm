/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:06:48 by lodovico          #+#    #+#             */
/*   Updated: 2021/04/28 13:24:42 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

int		main(void)
{
	char	*str1 = "la cacca\n";
	int		ret;
	//char	str2[13];
	
	//printf("my result: %s\ncunt result: %s", ft_strcpy(str2, str1), strcpy(str2, str1));
	ret = ft_write(-1, str1, 6);
	printf("return: %d\n", ret);
	printf ("Error no is : %d\n", errno);
	ret = write(-1, str1, 6);
	printf("return: %d\n", ret);
	printf ("Error no is : %d\n", errno);
	//ret = write(1, str1, -6);
	//printf("return: %d\n", ret);
	return(0);
}