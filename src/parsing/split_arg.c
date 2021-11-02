/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <lchristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:22:21 by viporten           #+#    #+#             */
/*   Updated: 2021/11/01 10:02:40 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_new_arg(int *i, int *j, char *str)
{
	e_quote	quote;

	quote = NONE;
	while (str[(*i)] == ' ')
		(*i)++;
	*j = *i;
	while (str[(*i)])
	{
		quote = update_quote_status(str[(*i)], quote);
		if (is_separator(str[(*i)]) == 1 && quote == NONE)
			break ;
		(*i)++;	
	}
	return (0);
}


int	add_new_token(int i, int j, char *str, t_commande_line **stc)
{
	t_token	*tmp;
	t_token	*new;

	tmp = (*stc)->first_token;
	new = malloc(sizeof(t_token));
	if (new == NULL)
		return (50);
	init_token(new);
	new->str = malloc(sizeof(char *) * (i - j + 1)); 
	if (new->str == NULL)
		return (free_token_ret_malloc_error(new));
	new->str = ft_strncpy(new->str, str + j, i - j);
	init_type(new);
	if (tmp == NULL)
		(*stc)->first_token = new;
	else
	{
		while ((*stc)->first_token->next)
			(*stc)->first_token = (*stc)->first_token->next;
		(*stc)->first_token->next = new;
		(*stc)->first_token = tmp;
	}
	return (0);
}

void	iter_to_end_or_redirection(char	*str, int *i)
{
	while (str[(*i)] && is_redirection(str[(*i)]))
		(*i)++;
}
/*ici on decoupe la string en arg*/
int	split(t_commande_line **stc)
{
	e_quote	quote;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	quote = NONE;
	if ((*stc)->string != NULL)
		len = ft_strlen((*stc)->string);
	while (i < len)
	{
		while (i < len && (*stc)->string[i] == ' ')
			i++;
		j = i;
		if ((*stc)->string[i] && is_redirection((*stc)->string[i]))
			iter_to_end_or_redirection((*stc)->string, &i);
		else
			get_new_arg(&i, &j, (*stc)->string);
		if (add_new_token(i, j, (*stc)->string, stc) > 0)
			return (50);//tester func mere
			
	}
	return (0);
}
/* ici on passe sur chaque commande line et on va les envoyer faire split la commande line en different arg*/
int	split_arg(t_commande_line **first)
{
	t_commande_line	*tmp;

	tmp = *first;
	while (*first)
	{
		if (split(first) > 0)
		{
			(*first) = tmp;
			return (50);
		}
		(*first) = (*first)->next;
	}
	(*first) = tmp;
	return (0);
}
