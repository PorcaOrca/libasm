/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:06:48 by lodovico          #+#    #+#             */
/*   Updated: 2021/04/28 11:22:53 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

int		main(void)
{
	char	*str1 = "la cacca";
	char	str2[13];
	
	printf("my result: %s\ncunt result: %s", ft_strcpy(str2, str1), strcpy(str2, str1));
	return(0);
}