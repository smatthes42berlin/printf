/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:46:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/29 08:46:31 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test/test_libftprintf.h"

char	*read_test_results(void);
void	process_results(char *file_content);

int	main(void)
{
	char	*file_content;

	file_content = read_test_results();
	printf("\n\n\nHi there \n\n\n");
	printf("%c", file_content[0]);
	printf("%c", file_content[1]);
	printf("%c", file_content[2]);
	printf("%c", file_content[3]);
	printf("%c", file_content[4]);
	printf("%c", file_content[5]);
	printf("%c", file_content[6]);
	printf("%c", file_content[7]);
	process_results(file_content);
	return (0);
}

char	*read_test_results(void)
{
	long	file_size;
	char	*file_content;
	int		fd;
	char	*file_path;
	int		close;
	int		readReturn;

	file_path = "./test/test/get_output/test_res.txt";
	fd = open_file_fd(file_path, O_RDONLY);
	printf("fd is %d\n", fd);
	file_size = get_file_size(file_path);
	file_content = malloc(sizeof(*file_content) * (file_size + 1));
	printf("size of file %ld\n\n", file_size);
	readReturn = read(fd, file_content, file_size);
	printf("\n\nread return: %d\n\n", readReturn);
	file_content[file_size] = '\0';
	close = close_file_fd(fd);
	if (!close)
		(NULL);
	return (file_content);
}

void	process_results(char *file_content)
{
	return ;
	// ft_split();
}