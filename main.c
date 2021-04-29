/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:06:48 by lodovico          #+#    #+#             */
/*   Updated: 2021/04/29 14:15:55 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

void	ft_read_test(int fd1, int fd2, int BUFF_SIZE)
{
	char	*buffer1;
	char	*buffer2;
	int		ret1;
	int 	ret2;
	int		errno1;
	int		errno2;

	buffer1 = malloc((BUFF_SIZE) * sizeof(char));
	buffer2 = malloc((BUFF_SIZE) * sizeof(char));
	ret1 = read(fd1, buffer1, BUFF_SIZE);
	errno1 = errno;
//	printf("\nbuffer: %s", buffer1);
	ret2 = ft_read(fd2, buffer2, BUFF_SIZE);
//	printf("\nbuffer: %s", buffer2);
	errno2 = errno;
	printf("\n");
	if (ret1 == ret2)
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
	if (errno1 == errno2)
		printf ("\033[0;32m[ERRNOOK]\033[0m");
	else
		printf("\033[0;31m[ERRNOKO]\033[0m");
	if (!strcmp(buffer1, buffer2))
		printf ("\033[0;32m[R&WOK]\033[0m");
	else
		printf("\033[0;31m[R&WKO]\033[0m");
	free(buffer1);
	free(buffer2);
}

void	ft_write_test(int fd1, int fd2, char *str)
{
	int ret1;
	int ret2;
	int errno1;
	int errno2;
	
	ret1 = write(fd1, str, strlen(str));
	errno1 = errno;
	ret2 = ft_write(fd2, str, strlen(str));
	errno2 = errno;
	printf("\n");
	if (ret1 == ret2)
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
	if (errno1 == errno2)
		printf ("\033[0;32m[ERRNOOK]\033[0m");
	else
		printf("\033[0;31m[ERRNOKO]\033[0m");
	if (strlen(str) > 2)
	{
		if (write(fd1, str, (strlen(str) / 2)) == ft_write(fd2, str, (strlen(str) / 2)))
			printf ("\033[0;32m[OK]\033[0m");
		else
			printf("\033[0;31m[KO]\033[0m");
	}
}

void	ft_test_strdup(char *src)
{
	char *dest1;
	char *dest2;
	
	dest1 = strdup(src);
	dest2 = ft_strdup(src);
	if (!strcmp(dest1, dest2))
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
	free(dest1);
	free(dest2);
}

void	ft_test_strcpy(char *src)
{
	char *dest1;
	char *dest2;
	
	dest1 = malloc((strlen(src) + 1) * sizeof(char));
	dest2 = malloc((strlen(src) + 1) * sizeof(char));
	if (!strcmp(strcpy(dest1, src), ft_strcpy(dest2, src)))
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
	free(dest1);
	free(dest2);
	dest1 = malloc((strlen(src) + 7) * sizeof(char));
	dest2 = malloc((strlen(src) + 7) * sizeof(char));
	if (!strcmp(strcpy(dest1, src), ft_strcpy(dest2, src)))
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
	free(dest1);
	free(dest2);
}

void	ft_test_strcmp(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) == strcmp(str1, str2))
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
}

void	ft_test_strlen(char *str)
{
	if (ft_strlen(str) == strlen(str))
		printf ("\033[0;32m[OK]\033[0m");
	else
		printf("\033[0;31m[KO]\033[0m");
}

int		main(void)
{
	int 	fd1;
	int		fd2;
	printf("\033[0;36mSTRLEN TEST: \033[0m");
	ft_test_strlen("");
	ft_test_strlen(" ");
	ft_test_strlen("si vis pacem, para bellum");
	ft_test_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_test_strlen("0123456789");
	
	printf("\033[0;36m\nSTRCMP TEST: \033[0m");
	ft_test_strcmp("", "");
	ft_test_strcmp("", "yalla yalla");
	ft_test_strcmp("to be to t", "");
	ft_test_strcmp("asdrubale", "asdrubale");
	ft_test_strcmp("jhon connor", "jhon connol");
	ft_test_strcmp("jhon con", "jhon connol");
	ft_test_strcmp("jhon connor", "jhon");
	ft_test_strcmp("\n cariplo \n bnl \t framartino", "\n cariplo \n bnl \t framartino");
	ft_test_strcmp("\n cariplo \n bnl framartino", "\n cariplo \n bnl \t framartino");
	ft_test_strcmp("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_test_strcmp("", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_test_strcmp("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "");

	printf("\033[0;36m\nSTRCPY TEST: \033[0m");
	ft_test_strcpy("");
	ft_test_strcpy("yalla yalla");
	ft_test_strcpy("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_test_strcpy("comma comma comma");
	ft_test_strcpy("\n cariplo \n bnl \t framartino");
	
	printf("\033[0;36m\nSTRDUP TEST: \033[0m");
	ft_test_strdup("");
	ft_test_strdup("yalla yalla");
	ft_test_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_test_strdup("comma comma comma");
	ft_test_strdup("\n cariplo \n bnl \t framartino");
	
	fd1 = open("./this_is_the_file", O_CREAT | O_RDWR);
	fd2 = open("./it_s_my_file", O_CREAT | O_RDWR);
	
	printf("\033[0;36m\nWRITE RETURN TEST: \033[0m");
	ft_write_test(fd1, fd2, "our house\n");
	ft_write_test(fd1, fd2, "\n");
	ft_write_test(fd1, fd2, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	ft_write_test(fd1, fd2, "\n cariplo \n bnl \t framartino\n");
	ft_write_test(-2, -2, "\nla tua coda rotante scodinzola");
	ft_write_test(fd1, fd2, "");

	//close(fd1);
	//close(fd2);

	//fd1 = open("this_is_the_file", O_RDONLY);
	//fd2 = open("it_s_my_file", O_RDONLY);
	printf("\033[0;36m\nREAD TEST: \033[0m");
	ft_read_test(fd1, fd2, 10);
	ft_read_test(fd1, fd2, 10);
	ft_read_test(fd1, fd2, 10);
	ft_read_test(fd1, fd2, 10);
	ft_read_test(fd1, fd2, 10);
	ft_read_test(fd1, fd2, 10);


	
	close(fd1);
	close(fd2);
	
	return(0);
}