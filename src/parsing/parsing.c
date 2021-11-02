/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:48:20 by viporten          #+#    #+#             */
/*   Updated: 2021/10/25 20:04:02 by viporten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

e_quote	update_quote_status(char c, e_quote quote)
{
	if (c == '"')
	{
		if (quote == NONE)
			return (DOUBLE);
		else if (quote == DOUBLE)
			return (NONE);
	}
	else if (c == '\'')
	{
		if (quote == NONE)
			return (SINGLE);
		else if (quote == SINGLE)
			return (NONE);
	}
	return (quote);
}

e_quote	update_quote_succes(t_token *stc, int *i, e_quote quote)
{
	(*i)++;
	stc->expanded = true;
	return (quote);
}

int	unclose_quote(char	*str)
{
	int		i;
	e_quote	quote;

	i = 0;
	quote = NONE;
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (quote == NONE)
				quote = DOUBLE;
			else if (quote == DOUBLE)
				quote = NONE;
		}
		if (str[i] == '\'')
		{
			if (quote == NONE)
				quote = SINGLE;
			else if (quote == SINGLE)
				quote = NONE;
		}
		i++;
	}
	return (quote);
}
