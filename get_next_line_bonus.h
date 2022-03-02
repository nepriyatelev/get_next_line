/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:56:50 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/14 04:51:27 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd);
char	*ft_read(int fd, char *line_save);
char	*ft_line(char *line_save);
char	*ft_remainder(char *line_save);
char	*line_cpy(char *line, char *line_save);

#endif
