/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:06:48 by lodovico          #+#    #+#             */
/*   Updated: 2021/04/27 14:39:12 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

int		main(void)
{
	char	*str1 = "stringa lunga 16";
	
	printf("my result: %ld\ncunt result: %ld", ft_strlen(str1), strlen(str1));
	return(0);
}