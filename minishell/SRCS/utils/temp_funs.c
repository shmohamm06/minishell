/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_funs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:21:38 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/13 02:04:45 by hakaddou         ###   ########.fr       */
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
