/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 19:56:05 by bprado        #+#    #+#                 */
/*   Updated: 2019/02/14 20:58:35 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line);
#endif
