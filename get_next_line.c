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







// static int		gnl_part3(char **statstr, char ***line, char **str, char buff[])
// {
// 	char			*temp;

// 	temp = ft_strchr(buff, '\n');
// 	*statstr = ft_strdup(temp + 1);
// 	*temp = '\0';
// 	**line = ft_strjoin(*str, buff);
// 	free(*str);
// 	return (1);
// }








// static int		gnl_part4(char buff[], char ***line, int bytsread, char **str)
// {
// 	if ((bytsread < BUFF_SIZE || **str == 0) && bytsread != -3)
// 	{
// 		if (bytsread < 0)
// 		{
// 			// printf(" if bytsread < 0 \n");
// 			**line = NULL;
// 			free(*str);
// 			return (-1);
// 		}
// 		else if ((bytsread == 0) && (**str == 0))
// 		{
// 			// printf(" if bytsread == 0 \n");
// 			// printf("line 67, bytsread: %d\n", bytsread);
// 			// (statstr == 0) ? printf("true") : printf("false");
// 			**line = NULL;
// 			free(*str);
// 			return (0);
// 		}
// 		// else if (bytsread == 0 || **str == 0)
// 		// {
// 		// 	// printf("line 67, bytsread: %d\n", bytsread);
// 		// 	free(*str);
// 		// 	return (0);
// 		// }
// 	}
// 	buff[bytsread] = 0;
// 	**line = ft_strjoin(*str, buff);
// 	free(*str);
// 	return (1);
// }



// static void		gnl_part2(char buff[], char **statstr, int *bytsread, char ***line)
// {
// 	char			*temp;
// 	// char			*str;

// 	// str = ft_strnew(0);
// 	ft_strncpy(buff, *statstr, BUFF_SIZE);
// 	*bytsread = -2;
// 	temp = ft_strchr(*statstr, '\n');
// 	// (temp) ? printf("temp true") : printf("temp false");
// 	if (temp)
// 		statstr = ft_memmove(*statstr, temp, ft_strlen(temp));
// 	else
// 	{
// 		// *statstr = NULL;
// 		*bytsread = -3;
// 		**line = ft_strdup(*statstr);
// 		*statstr = NULL;
// 	}
// 		// gnl_part4(buff, line, *bytsread, &str);
// 	// printf("part2....");
// }




// static void		initialize(char **str, int *bytsread, char buff[])
// {
// 	*str = ft_strnew(0);
// 	// *temp = ft_strnew(0);
// 	*bytsread = 0;
// 	buff[BUFF_SIZE] = 0;
// }








// int				get_next_line(const int openfd, char **line)
// {
// 	int				bytsread;
// 	char			buff[BUFF_SIZE + 1];
// 	char			*str;
// 	char			*temp;
// 	static char		*statstr;

// 	initialize(&str, &bytsread, buff);
// 	if (statstr == 0)
// 	{
// 		bytsread = read(openfd, buff, BUFF_SIZE);
// 		// printf("statstr == 0\n");
// 	}
// 	if (!(line) || (bytsread < 0))
// 		return (-1);
// 	// (statstr != NULL) ? printf("true") : printf("false");
// 	if (statstr != NULL)
// 		gnl_part2(buff, &statstr, &bytsread, &line);
// 	while (bytsread > -1 || bytsread == -2)
// 	{
// 		if (ft_strchr(buff, '\n'))
// 			return (gnl_part3(&statstr, &line, &str, buff));
// 		if (bytsread < BUFF_SIZE && bytsread != -2)
// 			return (gnl_part4(buff, &line, bytsread, &str));
// 		temp = str;
// 		str = ft_strjoin(str, buff);
// 		free(temp);
// 		bytsread = read(openfd, buff, BUFF_SIZE);
// 		buff[BUFF_SIZE] = 0;
// 	}
// 	((*str == 0) && (statstr)) ? (free(statstr)) : (statstr);
// 	return (gnl_part4(buff, &line, bytsread, &str));
// }







// int				get_next_line(const int openfd, char **line)
// {
// 	int				bytsread;
// 	char			buff[BUFF_SIZE + 1];
// 	char			*str;
// 	char			*temp;
// 	static char		*statstr;
// 	// char			*temp;

// 	// initialize(&str, &bytsread, buff);
// 	str = ft_strnew(0);
// 	bytsread = 0;
// 	buff[BUFF_SIZE] = 0;

// 	if (statstr == 0)
// 		bytsread = read(openfd, buff, BUFF_SIZE);
// 	if (!(line) || (bytsread < 0))
// 		return (-1);
// 	if (statstr != NULL)
// 	{
// 		// ********    gnl_part2(buff, &statstr, &bytsread); 

// 		ft_strncpy(buff, statstr, BUFF_SIZE);
// 		bytsread = -2;
// 		temp = ft_strchr(statstr, '\n');
// 		if (temp)
// 			statstr = ft_memmove(statstr, temp, ft_strlen(temp));
// 		else
// 			ft_bzero(statstr, ft_strlen(statstr));
// 	}
// 	while (bytsread > -1 || bytsread == -2)
// 	{
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			// ********    return (gnl_part3(&statstr, &line, &str, buff));

// 			temp = ft_strchr(buff, '\n');
// 			statstr = ft_strdup(temp + 1);
// 			*temp = '\0';
// 			*line = ft_strjoin(str, buff);
// 			free(str);
// 			return (1);
// 		}
// 		if (bytsread < BUFF_SIZE && bytsread != -2)
// 		{
// 			// ********    return (gnl_part4(buff, &line, bytsread, &str));
// 			if (bytsread < BUFF_SIZE || *str == 0)
// 			{
// 				*line = NULL;
// 				if (bytsread < 0)
// 				{
// 					free(str);
// 					return (-1);
// 				}
// 				else if (bytsread == 0 && *str == 0)
// 				{
// 					free(str);
// 					return (0);
// 				}
// 				// else if (bytsread == 0 || *str == 0)
// 				// {
// 				// 	free(str);
// 				// 	return (0);
// 				// }
// 			}
// 			buff[bytsread] = 0;
// 			*line = ft_strjoin(str, buff);
// 			free(str);
// 			return (1);
// 		}
// 		temp = str;
// 		str = ft_strjoin(str, buff);
// 		free(temp);
// 		bytsread = read(openfd, buff, BUFF_SIZE);
// 		buff[BUFF_SIZE] = 0;
// 	}
// 	((str == 0) && (statstr)) ? (free(statstr)) : (statstr);
// 	// ********    return (gnl_part4(buff, &line, bytsread, &str));
// 	if (bytsread < BUFF_SIZE || *str == 0)
// 	{
// 		*line = NULL;
// 		if (bytsread < 0)
// 		{
// 			free(str);
// 			return (-1);
// 		}
// 		else if (bytsread == 0 && *str == 0)
// 		{
// 			free(str);
// 			return (0);
// 		}
// 		else if (bytsread == 0 || *str == 0)
// 		{
// 			free(str);
// 			return (0);
// 		}
// 	}
// 	buff[bytsread] = 0;
// 	*line = ft_strjoin(str, buff);
// 	free(str);
// 	return (1);
// }







// // returning 0 intead of 1 on 12345678

// buff of different sizes 
// buff ending on newline


// int		get_next_line(int fd, char **line)
// {
// 	char			buff[BUFF_SIZE + 1];
// 	static char		*holder;
// 	char			*temp;
// 	int				ret;
// 	char			*str;

// 	ret = 0;
// 	buff[BUFF_SIZE] = 0;
// 	str = ft_strnew(0);
// 	if (!(holder))
// 		ret = read(fd, buff, BUFF_SIZE);
// 	if (!(line) || ret < 0)
// 		return (-1);
// 	if (holder)
// 	{
// 		//function will pass through here everytime it's called in the main and holder has content
// 		ft_strncpy(buff, holder, BUFF_SIZE);
// 		// move holder pointer down to newline, if not present free holder
// 		// test contents of holder, check if it should just be holder += BUFF_SIZE;
// 		ret = ft_strlen(buff);
// 		// if the length of buff is less than BUFF_SIZE, it still needs to pass through read
// 		holder = ft_memmove(holder, (holder + ret), ret);
// 		if (ret == 0)
// 		// do I need to / can I free holder?
// 		// holder malloced through ft_strdup whithin the while loop later on
// 		// or should holder = NULL ?
// 			free(holder);
// 		ret = -2;
// 	}
// 	while(ret > 0 || ret == -2)
// 	{
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			// this will relate to the holder
// 			// must consider str having nothing because of previous holder copying to buff
// 			// and reaching here, and str having content through cycling in the while loop
// 			temp = ft_strchr(buff, '\n');
// 			holder = ft_strdup(temp + 1);
// 			//what happens when holder = '\0' ?
// 			// answer: the ret will be set to strlen of buff thru holder, and because of being
// 			// \0, it will not pass through this while statement.
// 			*temp = '\0';
// 			*line = ft_strjoin(str, buff);
// 			if (str)
// 				free(str);
// 			// do i need to free anything?
// 			return (1);
// 		}
// 		if (ret < BUFF_SIZE && ret != -2)
// 		{
// 			// should this return 1 or 0, why?
// 			// i don't need to account for ret being less that 0 due to the while expression
// 			buff[ret] = '\0';
// 			*line = ft_strjoin(str, buff);
// 			if (str)
// 				free(str);
// 			return (1);
// 		}
// 		temp = str;
// 		str = ft_strjoin(str, buff);
// 		free(temp);
// 		ret = read(fd, buff, BUFF_SIZE);
// 		buff[ret] = '\0';
// 	}
// 	// ret is 0 or less
// 	// cases that fall here include: first read is 0, second read is 0 or less, length of buff is 0 
// 	// when holder value was assigned. 
// 	if (ret < 0)
// 		//do i need to free anything
// 		return (-1);
// 	if (ret == 0 && *str > 0)
// 	{
// 		buff[ret] = '\0';
// 		*line = ft_strjoin(str, buff);
// 		if (str)
// 			free(str);
// 		return (1);
// 	}
	

// 	*line = NULL;
// 	return (0);
// }


// below version failing test 40 in molitest with buffer size 7. unknown reason

// int		get_next_line(int fd, char **line)
// {
// 	char			*buff;
// 	static char		*holder;
// 	char			*temp;
// 	int				ret;
// 	char			*str;

// 	ret = 0;
// 	// buff[BUFF_SIZE] = 0;
// 	buff = ft_strnew(BUFF_SIZE);
// 	str = ft_strnew(0);

// 	if (!(holder))
// 		ret = read(fd, buff, BUFF_SIZE);

// 	if (!(line) || ret < 0)
// 		return (-1);
// 	if (holder)
// 	{

// 		ft_strncpy(buff, holder, BUFF_SIZE);
// 		ret = ft_strlen(buff);
// 		holder = ft_memmove(holder, (holder + ret), ret);
// 		if (ret == 0)
// 		{
// 			free(holder);
// 			holder = NULL;
// 		}
// 		ret = -2;
// 	}
// 	while(ret > 0 || ret == -2)
// 	{
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			temp = ft_strchr(buff, '\n');
// 			*temp = '\0';
// 			if (holder)
// 				free(holder);
// 			holder = ft_strdup(temp + 1);
// 			*line = ft_strjoin(str, buff);
// 			if (str)
// 				free(str);
// 			free(buff);
// 			return (1);
// 		}
// 		if (ret < BUFF_SIZE && ret != -2)
// 		{
// 			buff[ret] = '\0';
// 			*line = ft_strjoin(str, buff);
// 			if (str)
// 				free(str);
// 			free(buff);
// 			return (1);
// 		}
// 		temp = str;
// 		str = ft_strjoin(str, buff);
// 		free(temp);
// 		ret = read(fd, buff, BUFF_SIZE);
// 		buff[ret] = '\0';
// 	}
// 	if (ret < 0)
// 		return (-1);
// 	if (ret == 0 && *str > 0)
// 	{
// 		buff[ret] = '\0';
// 		*line = ft_strjoin(str, buff);
// 		if (str)
// 			free(str);
// 		free(buff);
// 		return (1);
// 	}
// 	*line = NULL;
// 	free(buff);
// 	return (0);
// }



// ? printf("True\n") : printf("False\n");



// static int		add_to(char buf[], char **hold)
// {																			//holder will not contain more than BUFF_SIZE
// 	ft_memcpy(buf, *hold, BUFF_SIZE);
// 	return (ft_strlen(buf));
// }







// int		get_next_line(int fd, char **line)
// {
// 	static char		*hold[1024];
// 	int				ret;
// 	char			buf[BUFF_SIZE + 1];
// 	char			*str;

// 	if (read(fd, buf, 0) < 0 || fd < 0 || !line)
// 		return (-1);
// 	buf[BUFF_SIZE] = '\0';													// (!(holder[fd])) ? read(fd, buff, BUFF_SIZE) : add_to_buff(buff, holder[fd]);
// 	ret = (hold[fd]) ? add_to(buf, &hold[fd]) : read(fd, buf, BUFF_SIZE);	// ft_strsub(hold, 0, ft_strlen(hold[fd]));
// 	(hold[fd]) ? ft_strdel(&hold[fd]) : hold[fd];							// at this point buff is filled with read() or *holder
// 	hold[fd] = ft_strnew(0);
// 	while (ret > 0 && !(ft_strchr(buf, '\n'))) 								// buff may contain more than one newline received from *holder
// 	{																		// should I check here if buff[] contains '\n'
// 		str = hold[fd];
// 		hold[fd] = ft_strjoin(hold[fd], buf);									// check '\n' and add to str or directly to **line
// 		(str) ? ft_strdel(&str) : str;
// 		ret = read(fd, buf, BUFF_SIZE);
// 		buf[ret] = '\0';
// 	}																		// at this point either buff contains a '\n' or read() == 0
// 	str = ft_strchr(buf, '\n');
// 	if (str || ((ft_strlen(buf) < BUFF_SIZE) && (hold[fd][0] != '\0')))
// 	{
// 		*line = (!str) ? ft_strjoin(hold[fd], buf) : NULL;
// 		(!str) ? ft_strdel(&hold[fd]) : hold[fd];
// 		if (!str)
// 			return (1);
// 		*str = '\0';
// 		*line = ft_strjoin(hold[fd], buf);
// 		(hold[fd]) ? ft_strdel(&hold[fd]) : hold[fd];
// 		hold[fd] = (ft_strlen(str + 1)) ? ft_strdup(str + 1) : NULL;
// 		return (1);
// 	}																		// from here read() == 0
// 	*line = hold[fd];
// 	(hold[fd]) ? ft_strdel(&hold[fd]) : hold[fd];
// 	if (!hold[fd] && *buf == '\0' && ret == 0)
// 		*line = NULL;
// 	return (0);
// }







// static int		add_to(char buf[], char **hold, int fd)
// {																			//holder will not contain more than BUFF_SIZE
// 	ft_memcpy(buf, *hold, BUFF_SIZE);
// 	ft_strdel(&hold[fd]);
// 	return (ft_strlen(buf));
// }






static void		join_and_read(char **str, char **h, char buf[], int fd)
{
	*str = *h;
	*h = ft_strjoin(*str, buf);
	(str) ? ft_strdel(&*str) : str;
	buf[read(fd, buf, BUFF_SIZE)] = '\0';
}

static int		join_and_return(char **line, char **str, char **h, char buf[])
{
	*line = (!*str) ? ft_strjoin(*h, buf) : NULL;
	(!*str) ? ft_strdel(&*h) : h;
	if (!*str)
		return (1);
	**str = '\0';
	*line = ft_strjoin(*h, buf);
	(*h) ? ft_strdel(&*h) : h;
	*h = (ft_strlen(*str + 1)) ? ft_strdup(*str + 1) : NULL;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*h[1024];
	char			buf[BUFF_SIZE + 1];
	char			*str;

	if (read(fd, buf, 0) < 0 || fd < 0 || !line || fd > 1024)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	(h[fd]) ? ft_memcpy(buf, h[fd], BUFF_SIZE) : (void*)read(fd, buf, BUFF_SIZE);
	ft_strdel(&h[fd]);
	h[fd] = ft_strnew(0);
	while (*buf > 0 && !(ft_strchr(buf, '\n')))
		join_and_read(&str, &h[fd], buf, fd);
	str = ft_strchr(buf, '\n');
	if (str || ((ft_strlen(buf) < BUFF_SIZE) && (h[fd][0] != '\0')))
		return (join_and_return(line, &str, &h[fd], buf));
	*line = h[fd];
	(h[fd]) ? ft_strdel(&h[fd]) : h;
	if (!h[fd] && *buf == '\0')
		*line = NULL;
	return (0);
}










// int		main(int argc, char *argv[])
// {
// 	int			openfd;
// 	int			i;
// 	char		buff[BUFF_SIZE + 1];
// 	char		*line;
// 	int			j;

// 	openfd = open(argv[1], O_RDONLY);

// 	if (openfd == -1){
// 		ft_putstr("Error opening the following file: ");
// 		ft_putstr(argv[1]);
// 	}

// 	i = 1;
// 	if (openfd != -1){
// 		j = 0;
// 		// while(++j < 10)
// 		while (i)
// 		{
// 		i = get_next_line(openfd, &line);
// 		// printf("----This is buffsize %d, return:%d, string:|%s|\n",BUFF_SIZE, i, /*ft_strcmp("aaa", line),*/ line);
// 		printf("line: %d -->%s\n", j, line);
// 		++j;
// 		if (i != 0)
// 			free(line);
// 		}
// 	}
// 	close(openfd);
// 	// printf("This is the first string: \n%s", line);// line[0]);
// 	// while (1)
// 	// {
		
// 	// }



// 	// char 	*line;
// 	// int		out;
// 	// int		p[2];
// 	// char 	*str;
// 	// int		len = 50;

// 	// str = (char *)malloc(1000 * 1000);
// 	// *str = '\0';
// 	// while (len--)
// 	// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	// out = dup(1);
// 	// pipe(p);
// 	// dup2(p[1], 1);

// 	// if (str)
// 	// 	write(1, str, strlen(str));
// 	// close(p[1]);
// 	// dup2(out, 1);
// 	// get_next_line(p[0], &line);
// 	// printf("line-->%s<--line\n\n\n\n\n\n\n\n\n", line);
// 	// printf("line-->%s<--line\n", str);
// 	// (strcmp(line, str) == 0) ? (printf("strcmp TRUE")) : (printf("strcmp FALSE"));


// 	return (0);
// }
