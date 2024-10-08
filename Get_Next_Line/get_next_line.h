/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:49:16 by pevieira          #+#    #+#             */
/*   Updated: 2023/07/01 11:40:18 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_and_stash(int fd, char *static_buffer);
char	*ft_strjoin_gnl(char *stash, char *temp);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *str);
char	*ft_rest(char *string);
char	*ft_line_to_get(char *string);

#endif