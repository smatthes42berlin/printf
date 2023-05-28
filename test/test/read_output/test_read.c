/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:46:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/05/28 18:23:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test/test_libftprintf.h"

void	get_test_results(void);

int	main(void)
{
	get_test_results();
	return (0);
}

void	get_test_results(void)
{
	long	file_size;
	char	*file_content;
	int		fd;
	char	*file_path;
	int		close;
	int		res;

	file_path = "../get_output/test_res.txt";
	fd = open_file_fd(file_path, O_RDONLY);
	file_size = get_file_size(file_path);
	file_content = malloc(sizeof(*file_content) * (file_size + 1));
	res = read(fd, file_content, file_size);
	file_content[file_size] = '\0';
    printf("%s", file_content);
	close = close_file_fd(fd);
	if (!close)
		return ;
	printf("%s", file_content);
	return ;
}
