/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:58:48 by viporten           #+#    #+#             */
/*   Updated: 2021/10/27 00:04:12 by viporten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_pipe(int *i, char *str)
{
	e_quote	quote;

	quote = NONE;
	while (str[*i])
	{
		quote = update_quote_status(str[*i], quote);
		if (str[*i] == '|' && quote == NONE)
			return ;
		(*i)++;
	}
	return ;
}

void	init_cmdl(t_commande_line *new)
{
	new->string = NULL;
	new->first_token = NULL;
	new->envp = NULL;
	new->next = NULL;
}

int	get_new_cmdl(char *str, int i, int j, t_commande_line **first)
{
	t_commande_line	*tmp;
	t_commande_line	*new;

	tmp = *first;
	new = malloc(sizeof(t_commande_line));
	if (new == NULL)
		return (50);
	init_cmdl(new);
	new->string = malloc(sizeof(char) * (i - j + 1));
	if (new->string == NULL)
		return (free_cmdl_ret_malloc_error(new));
	new->string = ft_strncpy(new->string, str + j, i - j);
	if (tmp == NULL)
		*first = new;
	else
	{
		while ((*first)->next)
			*first = (*first)->next;
		(*first)->next = new;
		*first = tmp;
	}
	return (0);
}

void	add_envp_to_cmdl(t_commande_line **first, char **envp)
{
	t_commande_line	*cur;

	cur = NULL;
	cur = *first;
	while (cur)
	{
		cur->envp = envp;
		cur = cur->next;
	}
}

int	get_cmd_line(char *string, t_commande_line **first, char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string[i])
	{
		if (i != 0)
		{
			i++;
			j++;
		}
		get_pipe(&i, string);
		if (get_new_cmdl(string, i, j, first) > 0)
			return (50);
		j = i;
	}
	add_envp_to_cmdl(first, envp);
	return (0);
}
