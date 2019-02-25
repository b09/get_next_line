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

static void		gnl_part2(char buff[], char **statstr, int *bytsread)
{
	char			*temp;

	ft_strncpy(buff, *statstr, BUFF_SIZE);
	*bytsread = -2;
	temp = ft_strchr(*statstr, '\n');
	if (temp)
		statstr = ft_memmove(*statstr, temp, ft_strlen(temp));
	else
		ft_bzero(statstr, ft_strlen(*statstr));
}

static int		gnl_part3(char **statstr, char ***line, char **str, char buff[])
{
	char			*temp;

	temp = ft_strchr(buff, '\n');
	if (temp + 1 != 0)
		*statstr = ft_strdup(temp + 1);
	else
		free(*statstr);
	printf("hey:%s-\n", *statstr);
	*temp = '\0';
	**line = ft_strjoin(*str, buff);
	free(*str);
	return (1);
}

static int		gnl_part4(char buff[], char ***line, int bytsread, char **str)
{
	if (bytsread < 0 || **str == 0)
	{
		**line = NULL;
		if (bytsread < 0)
		{
			free(*str);
			return (-1);
		}
		else
		{
			free(*str);
			return (0);
		}
	}
	buff[bytsread] = 0;
	**line = ft_strjoin(*str, buff);
	free(*str);
	return (1);
}

static void		initialize(char **str, char **temp, int *bytsread, char buff[])
{
	*str = ft_strnew(0);
	*temp = ft_strnew(0);
	*bytsread = 0;
	buff[BUFF_SIZE] = 0;
}

int				get_next_line(const int openfd, char **line)
{
	int				bytsread;
	char			buff[BUFF_SIZE + 1];
	char			*str;
	char			*temp;
	static char		*statstr;

	initialize(&str, &temp, &bytsread, buff);
	if (statstr == 0)
		bytsread = read(openfd, buff, BUFF_SIZE);
	if (!(line) || (bytsread < 0))
		return (-1);
	if (statstr != NULL)
		gnl_part2(buff, &statstr, &bytsread);
	while (bytsread > 0 || bytsread == -2)
	{
		if (ft_strchr(buff, '\n'))
			return (gnl_part3(&statstr, &line, &str, buff));
		if (bytsread < BUFF_SIZE && bytsread != -2)
			return (gnl_part4(buff, &line, bytsread, &str));
		str = ft_strjoin(str, buff);
		bytsread = read(openfd, buff, BUFF_SIZE);
		buff[BUFF_SIZE] = 0;
	}
	((*str == 0) && (statstr)) ? (free(statstr)) : (statstr);
	return (gnl_part4(buff, &line, bytsread, &str));
}

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
		printf("return of gnl:%d  string--->%s\n", i, line);
		free(line);
		}
	}
	free(line);
	close(openfd);
	// printf("This is the first string: \n%s", line);// line[0]);
	return (0);
}