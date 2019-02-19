/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 19:54:14 by bprado        #+#    #+#                 */
/*   Updated: 2019/02/14 21:00:37 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// allowed libc functions: read, malloc, free

// **line is the address of a pointer to a char used to save the line read from fd
// return value 1, 0, or -1 for line was read, reading completed  or error happened
// must output result without \n

int		get_next_line(const int openfd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		i;
	char 	*strjoin;
	strjoin = "Z";

	if (!(line))
		return (-1);
	i = read(openfd, buff, BUFF_SIZE);
	buff[BUFF_SIZE] = 0;
	while (i > 0)
	{
		if (ft_strchr(buff, '\n') != NULL)
		{
			strjoin = ft_strjoin(strjoin, buff);
		}
		i = read(openfd, buff, BUFF_SIZE);
	}
	line = &strjoin;
	return (1);
}

// char *ptr = "Pointer string";	ptr is the address of the string currently pointing to the first char
//									*ptr is the char the pointer points to, in this case 'P'
//									&*ptr is the address of the pointer to the string

int		main(int argc, char *argv[])
{
	int			i;
	int			openfd;
	char		a;
	char		buff[BUFF_SIZE + 1];
	char		**line;

	openfd = open(argv[1], O_RDONLY);

	if (openfd == -1){
		ft_putstr("Error opening the following file: ");
		ft_putstr(argv[1]);
	}

	if (openfd != -1){
		i = get_next_line(openfd, line);
		// while ((i = get_next_line(openfd, line)))
		// {

		// }
	}



	printf("This is the first string: %s", *line);
	return (0);
}



