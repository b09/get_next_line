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
	int		readRetInt;
	char 	*str;
	str = "";
	int		j;

	if (!(line))
		return (-1);
	readRetInt = read(openfd, buff, BUFF_SIZE);
	// j = readRetInt;
	buff[BUFF_SIZE] = 0;
	if (readRetInt == 0)
	{
		str = ft_strjoin(str, buff);
		*line = str;
		return (readRetInt);
	}
	if (readRetInt == -1)
		return (readRetInt);
	while (readRetInt > 0)// && !(ft_strchr(buff, '\0')))
	{
		buff[BUFF_SIZE] = 0;
		if (readRetInt < BUFF_SIZE)//(ft_strchr(buff, '\0'))
			buff[readRetInt] = 0;
		str = ft_strjoin(str, buff);
		readRetInt = read(openfd, buff, BUFF_SIZE);
	}
	*line = str;
	return (1);
}


//strjoin will copy all elements of string array up until null char, and will add null to the end of the copied string
//strchr will return a pointer to the part of a string where a char was found. 


// char *ptr = "Pointer string";	ptr is the address of the string currently pointing to the first char
//									*ptr is the char the pointer points to, in this case 'P'
//									&*ptr is the address of the pointer to the string

int		main(int argc, char *argv[])
{
	// char		*i;
	int			openfd;
	char		a;
	char		buff[BUFF_SIZE + 1];
	char		*line;

	openfd = open(argv[1], O_RDONLY);

	if (openfd == -1){
		ft_putstr("Error opening the following file: ");
		ft_putstr(argv[1]);
	}

	if (openfd != -1){
		get_next_line(openfd, &line);
	}
	printf("This is the first string: \n%s", line);// line[0]);
	return (0);
}



