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

// 1. a variable containing multiple strings to be read
// 2. main using get_next_line to print each line. 
// 3. read function that will "read into a buffer" until it reaches a \n 
// 4. write func will write into stream indentified by fd













// static int		gnl_part2(char buff[], long long bytsRead, char **line, const int openfd, char *str)
// {
// 	static char 	*statstr;
// 	char *temp;

// 	if (statstr != NULL)
// 		str = ft_strjoin(str, statstr);
// 	while (bytsRead > 0)
// 	{
// 		if (bytsRead < BUFF_SIZE)
// 		{
// 			buff[bytsRead] = 0;
// 			*line = ft_strjoin(str, buff);
// 			return (0);
// 		}
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			statstr = ft_strdup((ft_strchr(buff, '\n') + 1));
// 			temp = ft_strchr(buff, '\n');
// 			*temp = '\0';
// 				// buff[BUFF_SIZE - ft_strlen(ft_strchr(buff, '\n'))] = 0;
// 			*line = ft_strjoin(str, buff);
// 			return (1);
// 		}
// 		str = ft_strjoin(str, buff);
// 		bytsRead = read(openfd, buff, BUFF_SIZE);
// 		buff[BUFF_SIZE] = 0;
// 	}
// 	return (0);
// }




//  buff["abcde ^ 12345 ^ 6789b ^ b\nfgh ^ ij**\n ^ klmno ^ **\n"]
//  statstr = "fghij** \n klmno** \n"

// open is excuted
// gnl checks validity of fd and **line 
// gnl reads from fd and inserts into buff the contents provided by read 
// buff adds to &line its contents if there is no \n 
// when a \n is detected, buffs contents after \n are copied to static variable 
// the contents of stat var are added back to buff up until BUFF_SIZE or \n, whichever comes first 

// int		gnl_part3()

// int		gnl_part2(const int openfd, char **line, int bytsRead, char buff[], char *temp, char **statstr, char *str)
// {
// 	while (bytsRead > 0 || bytsRead == -2)
// 	{
// 		if (bytsRead == -1)
// 			return (-1);
// 		temp = ft_strchr(buff, '\n');
// 		if (temp)
// 		{
// 			*statstr = ft_strdup(temp + 1);
// 			*temp = '\0';
// 			*line = ft_strjoin(str, buff);
// 			return (1);
// 		}		
// 		if (bytsRead < BUFF_SIZE && bytsRead > 0)
// 		{
// 			printf("hey\n");
// 			buff[bytsRead] = 0;
// 			*line = ft_strjoin(str, buff);
// 			return (0);
// 		}
// 		str = ft_strjoin(str, buff);
// 		bytsRead = read(openfd, buff, BUFF_SIZE);
// 	}
// 	*line = NULL;
// 	return (0);
// }

// int		get_next_line(const int openfd, char **line)
// {
// 	int				bytsRead;
// 	char			buff[BUFF_SIZE + 1];
// 	char 			*temp;
// 	static char 	*statstr;
// 	char			*str;

// 	str = ft_strnew(0);
// 	buff[BUFF_SIZE] = 0;
// 	if (statstr == 0)
// 		bytsRead = read(openfd, buff, BUFF_SIZE);
// 	if (!(line) || (bytsRead < 0))
// 		return (-1);
// 	if (statstr != NULL)
// 	{
// 		ft_strncpy(buff, statstr, BUFF_SIZE);
// 		bytsRead = -2;  //ft_strlen(buff);
// 		temp = ft_strchr(statstr, '\n');
// 		if (temp)
// 			statstr = ft_memmove(statstr, temp, ft_strlen(temp));
// 		else
// 			ft_bzero(statstr, ft_strlen(statstr));
// 	}
// 	return (gnl_part2(openfd, line, bytsRead, buff, temp, &statstr, str));
// }






static void		gnl_part2(char buff[], char **statstr, int *bytsRead)
{
	char 	*temp;

	ft_strncpy(buff, *statstr, BUFF_SIZE);
	*bytsRead = -2; 
	temp = ft_strchr(*statstr, '\n');
	if (temp)
		statstr = ft_memmove(*statstr, temp, ft_strlen(temp));
	else
		ft_bzero(statstr, ft_strlen(*statstr));
}



static int		gnl_part3(char **statstr, char ***line, char **str, char buff[])
{
	char 	*temp;

	temp = ft_strchr(buff, '\n');
	*statstr = ft_strdup(temp + 1);
	*temp = '\0';
	**line = ft_strjoin(*str, buff);
	return (1);
}





static int		gnl_part4(char buff[], char ***line, int bytsRead, char **str)
{
	if (bytsRead == -1)
	{
		*line = NULL;
		return (-1);
	}
	buff[bytsRead] = 0;
	**line = ft_strjoin(*str, buff);
	return (0);
}






static void		initialize(char **str, char **temp, int	*bytsRead, char buff[])
{
	*str = ft_strnew(0);
	*temp = ft_strnew(0);
	*bytsRead = 0;
	buff[BUFF_SIZE] = 0;
}






int		get_next_line(const int openfd, char **line)
{
	int				bytsRead;
	char			buff[BUFF_SIZE + 1];
	char 			*str;
	char 			*temp;
	static char 	*statstr;										//bytsRead, buff, str, temp, statstr, openfd, line

	initialize(&str, &temp, &bytsRead, buff);
	if (statstr == 0)
		bytsRead = read(openfd, buff, BUFF_SIZE);
	if (!(line) || (bytsRead < 0))
		return (-1);
	if (statstr != NULL)
		gnl_part2(buff, &statstr, &bytsRead);
	while (bytsRead > 0 || bytsRead == -2)
	{
		temp = ft_strchr(buff, '\n');
		if (temp || bytsRead == -1)
			return (gnl_part3(&statstr, &line, &str, buff));
		if (bytsRead < BUFF_SIZE && bytsRead > 0)
			return (gnl_part4(buff, &line, bytsRead, &str));
		str = ft_strjoin(str, buff);
		bytsRead = read(openfd, buff, BUFF_SIZE);
		buff[BUFF_SIZE] = 0;
	}
	*line = NULL;
	return (0);
}


int		get_next_line(const int openfd, char **line)
{
	int				bytsRead;
	char			buff[BUFF_SIZE + 1];
	char 			*str;
	char 			*temp;
	static char 	*statstr;										//bytsRead, buff, str, temp, statstr, openfd, line

	str = ft_strnew(0);
	temp = ft_strnew(0);
	bytsRead = 0;
	buff[BUFF_SIZE] = 0;
	if (statstr == 0)
		bytsRead = read(openfd, buff, BUFF_SIZE);
	if (!(line) || (bytsRead < 0))
		return (-1);
	if (statstr != NULL)
	{
		ft_strncpy(buff, statstr, BUFF_SIZE);
		bytsRead = -2; 
		temp = ft_strchr(statstr, '\n');
		if (temp)
			statstr = ft_memmove(statstr, temp, ft_strlen(temp));
		else
			ft_bzero(statstr, ft_strlen(statstr));
	}
	while (bytsRead > 0 || bytsRead == -2)
	{
		if (bytsRead == -1)
		{
			*line = NULL;
			return (-1);
		}
		temp = ft_strchr(buff, '\n');
		if (temp)
		{
			statstr = ft_strdup(temp + 1);
			*temp = '\0';
			*line = ft_strjoin(str, buff);
			return (1);
		}		
		if (bytsRead < BUFF_SIZE && bytsRead > 0)
		{
			buff[bytsRead] = 0;
			*line = ft_strjoin(str, buff);
			return (0);
		}
		str = ft_strjoin(str, buff);
		bytsRead = read(openfd, buff, BUFF_SIZE);
		buff[BUFF_SIZE] = 0;
	}
	*line = NULL;
	return (0);
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
	int			openfd;
	int			i;
	char		buff[BUFF_SIZE + 1];
	char		*line;
	int			j;

	openfd = open(argv[1], O_RDONLY);

	if (openfd == -1){
		ft_putstr("Error opening the following file: ");
		ft_putstr(argv[1]);
	}

	if (openfd != -1){
		j = 0;
		while(++j < 10)
		{
		i = get_next_line(openfd, &line);
		printf("----This is string %d:%d %s\n",j, i, line);
		}
	}
	free(line);
	close(openfd);
	// printf("This is the first string: \n%s", line);// line[0]);
	return (0);
}
