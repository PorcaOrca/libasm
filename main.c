/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:06:48 by lodovico          #+#    #+#             */
/*   Updated: 2021/04/28 10:56:02 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

int		main(void)
{
	char	*str1 = "";
	char	*str2 = "stringa lunga 16";
	
	printf("my result: %d\ncunt result: %d", ft_strcmp(str1, str2), strcmp(str1, str2));
	return(0);
}