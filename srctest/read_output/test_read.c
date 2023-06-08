/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:46:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/08 17:21:28 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_libftprintf.h"

t_res_pf	*read_test_results(void)
{
	long		file_size;
	char		*file_content;
	int			fd;
	char		*file_path;
	int			close;
	int			readReturn;
	t_res_pf	*res;

	res = NULL;
	file_path = "../results/test_results.txt";
	fd = open_file_fd(file_path, O_RDONLY);
	printf("fd is %d\n", fd);
	file_size = get_file_size(file_path);
	file_content = malloc(sizeof(*file_content) * (file_size + 1));
	printf("size of file %ld\n\n", file_size);
	readReturn = read(fd, file_content, file_size);
	printf("\n\nread return: %d\n\n", readReturn);
	file_content[file_size] = '\0';
	process_results(res, file_content);
	close = close_file_fd(fd);
	if (!close)
		return (NULL);
	return (res);
}

int	process_results(t_res_pf *res, char *file_content)
{
	char	**all_rows;
	char	**one_row;
	size_t	num_tests;
	size_t	i;

	i = 0;
	all_rows = ft_split_str(file_content, "\n");
	if (!all_rows)
		return (0);
	num_tests = ft_arr_len_char(all_rows);
	res = malloc(sizeof(*res) * (num_tests));
	if (!res)
		return (0);
	while (i < num_tests)
	{
		one_row = ft_split_str(all_rows[i], "-*-*-");
		res[i].print_is = one_row[1];
		res[i].print_should = one_row[0];
		res[i].return_is = one_row[2];
		res[i].return_should = one_row[3];
		i++;
	}
	return (1);
}

size_t	ft_arr_len_char(char **arr)
{
	size_t arr_len;

	arr_len = 0;
	if (!arr || !arr[0])
		return (arr_len);
	while (arr[arr_len])
		arr_len++;
	return (arr_len);
}