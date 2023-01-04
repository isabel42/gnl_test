/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:09:28 by itovar-n          #+#    #+#             */
/*   Updated: 2022/12/21 18:09:30 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_until_nl(char *s, int loopret);
char	*ft_get_line(char *line, int ret, char *buf, int fd);
int		ft_totalloop(char *buf);
char	*get_next_line(int fd);
char	*ft_calloc(size_t count, size_t size);
void	ft_free(char *s);

#endif
