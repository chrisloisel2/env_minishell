/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_extend_or_not.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:17:25 by viporten           #+#    #+#             */
/*   Updated: 2021/10/06 14:27:13 by viporten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*envp_unchange(int *i, char *str, char *word)
{
	int		j; 
	char	*s2;
	char	*new;
	int		len_word;

	j = 0;
	len_word = 0;
	s2 = NULL;
	new = NULL;
	if (word)
		len_word = ft_strlen(word);
	
}
