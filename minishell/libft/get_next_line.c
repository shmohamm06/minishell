/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:51:11 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/15 18:29:22 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char *save)
{
	char	*output;
	int		len_save;
	int		len_o;

	if (!ft_strchr(save, '\n'))
	{
		output = ft_strdup(save);
		save[0] = 0;
		return (output);
	}
	len_save = ft_strlen(save);
	len_o = ((unsigned long) ft_strchr(save, '\n') - (unsigned long) save + 1);
	output = (char *) ft_calloc(len_o + 1, sizeof(char));
	if (!output)
		return (NULL);
	ft_strlcpy(output, save, len_o + 1);
	ft_memmove(save, (save + len_o), (len_save - len_o + 1));
	return (output);
}

char	*ft_read(int fd, char *save)
{
	char	*output;
	char	*hold_save;
	char	*hold_new;
	size_t	end;

	end = 69;
	output = ft_line(save);
	if (ft_strchr(output, '\n'))
		return (output);
	while (!ft_strchr(output, '\n') && end)
	{
		end = read(fd, save, (size_t) BUFFER_SIZE);
		save[end] = 0;
		hold_save = ft_line(save);
		hold_new = ft_strjoin(output, hold_save);
		output = (char *) ft_free(output);
		hold_save = (char *) ft_free(hold_save);
		output = hold_new;
	}
	return (output);
}

/**
 * @brief Reads the file descriptor <fd> with buffer size of 4096 bytes until
 * it finds a new line. Then saving everything it read till the newline in
 * allocated memory.
 * 
 * @param fd 
 * @return a pointer to a string with the new line. NULL if it has failed to
 * read the file descriptor (fd) or reached EOF
 */
char	*get_next_line(int fd)
{
	char		*output;
	static char	save[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	output = ft_read(fd, save);
	if (!output)
		return (NULL);
	if (!output[0])
	{
		ft_free(output);
		return (NULL);
	}
	return (output);
}
