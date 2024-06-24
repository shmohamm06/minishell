/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_funs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:35 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:52:36 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	random_between(int min, int max)
{
	int				random_value;
	int				fd;
	ssize_t			result;
	unsigned int	range;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open /dev/urandom");
		exit(1);
	}
	result = read(fd, &random_value, sizeof(random_value));
	if (result != sizeof(random_value))
	{
		perror("Failed to read from /dev/urandom");
		exit(1);
	}
	close(fd);
	range = max - min + 1;
	return (min + (random_value % range));
}
