/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:18:48 by esukava           #+#    #+#             */
/*   Updated: 2020/08/10 16:00:34 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 5

int		get_next_line(const int fd, char **line)
{
	static char		buf[BUFF_SIZE + 1];
	int			ret;
	int	i = 0;

//	i = 0;
//	printf("%s %d\n", "i =", i);
	
	ret = read(fd, buf, BUFF_SIZE);
	printf("%s%s\n", "buf= ", buf);
	while (i < BUFF_SIZE &&  buf[i] != '\n')
	{	
		i++;
	}
	
	if (buf[i] == '\n')
	{
		buf[i] = '\0';	
		*line = ft_strjoin(*line, buf);
		return(1);
	}
	*line = ft_strjoin(*line, buf);
//	printf("%s %d %s %d \n", "i =", i, "ret =", ret);
	return(0);
}

int		main()
{
	
	char	*ret;
	static	int		fd;
	int		i;
	static int		rows;

	rows = 10;
	i = 0;

	fd = open("dracula.txt", O_RDONLY);
	while (i < rows)
	{
		if(get_next_line(fd, &ret) == 1)
		{
			i++;
			printf("%s\n", ret);
			free(ret);
		}	
	}
		close(fd);

//	printf("%s\n", ret);
}
