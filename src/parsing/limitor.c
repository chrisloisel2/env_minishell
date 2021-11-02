/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:01 by viporten           #+#    #+#             */
/*   Updated: 2021/10/13 17:40:35 by viporten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	limitor(t_token *stc, char *str)
{
	char	*new;

	new = NULL;
	new = devellope_limitor(stc, str);
	if (str)
		free(str);
	if (new == NULL)
		return (50);
	stc->str = new;
	return (0);
}
