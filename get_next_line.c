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

// allowed libc functions: read, malloc, free

// **line is the address of a pointer to a char used to save the line read from fd
// return value 1, 0, or -1 for line was read, reading completed  or error happened
// must output result without \n

static int		gnl_part2(char buff[], long long bytsRead, char **line, const int openfd, char *str)
{
	static char 	*statstr;

	if (statstr != NULL)
		str = ft_strjoin(str, statstr);
	while (bytsRead > 0)
	{
		if (bytsRead < BUFF_SIZE)
		{
			buff[bytsRead] = 0;
			*line = ft_strjoin(str, buff);
			return (0);
		}
		if (ft_strchr(buff, '\n'))
		{
			statstr = ft_strdup((ft_strchr(buff, '\n') + 1));
			buff[BUFF_SIZE - ft_strlen(ft_strchr(buff, '\n'))] = 0;
			*line = ft_strjoin(str, buff);
			return (1);
		}
		str = ft_strjoin(str, buff);
		bytsRead = read(openfd, buff, BUFF_SIZE);
		buff[BUFF_SIZE] = 0;
	}
	return (0);
}

int		get_next_line(const int openfd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	long long		bytsRead;
	int				i;
	char 			*str;

	str = ft_strnew(0);
	if (!(line))
		return (-1);
	bytsRead = read(openfd, buff, BUFF_SIZE);
	buff[BUFF_SIZE] = 0;
	if (bytsRead < 0)
		return (-1);
	i = gnl_part2(buff, bytsRead, line, openfd, str);
	return (i);
}



// line is str 
// str is ft_strjoin(str, buff) 




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
		printf("----This is string 1: %s\n", line);
		get_next_line(openfd, &line);
		printf("----This is string 2: %s\n", line);
		get_next_line(openfd, &line);
		printf("----This is string 3: %s\n", line);
		get_next_line(openfd, &line);
		printf("----This is string 4: %s\n", line);
	}
	// printf("This is the first string: \n%s", line);// line[0]);
	return (0);
}



