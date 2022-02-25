/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:01:57 by ysensoy           #+#    #+#             */
/*   Updated: 2022/02/25 17:27:03 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line_bonus(int fd);
char	*newlinedanonce_line(char *str);
char	*newlinedansonra_line(char *str);
char	*put_line(int fd, char *line[fd]);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
#endif
