/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:34:46 by viporten           #+#    #+#             */
/*   Updated: 2021/10/08 19:00:31 by viporten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
int     ft_truestrncmp(char *str, char *to, int n);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_strcat(char *s1, const char *s2);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int nbr);
int		ft_strncmp(char *str, char *to, int n);
int		ft_strcmp(char *str, char *in);
int		ft_atoi(char *str);
int		ft_is_alpha_num(char c);

#endif
