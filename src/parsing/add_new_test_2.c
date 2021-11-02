/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_test_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <lchristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:27:37 by laclide           #+#    #+#             */
/*   Updated: 2021/11/02 12:07:51 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_split_ret_str(char **split, char *str)
{
	free_split(split);
	return (str);
}

char	*new_token_env(t_token **stc, char **split, int i)
{
	t_token	*cur;
	t_token	*next;
	t_token	*new;

	if ((*stc))
		next = (*stc)->next;
	cur = *stc;
	while (split[i])
	{
		new = malloc(sizeof(t_token));
		if (new == NULL)
			return (free_split_ret_str(split, NULL));
		init_token(new);
		new->type = ARG;
		new->str = ft_strdup(split[i]);
		if (new->str == NULL)
		{
			if (new)
				free(new);
			return (free_split_ret_str(split, NULL));
		}
		if ((*stc))
			new->next = next;
		cur->next = new;
		cur = cur->next;
		i++;
	}
	*stc = cur;
	free_split(split);
	return (new->str);
}

/*
char	*env_unquote(t_token **stc, char *s2, char *s3)
{
	char	*s4;
	char	**split;
	t_token	*new;

	s4 = NULL;
	split = NULL;
	new = NULL;
	split = ft_strsplit(s2, ' ');
	if (split == NULL)
	{
		free(s3);
		return (free_str_ret_null(s2));
	}
	s4 = ft_strjoin(s3, split[0]);
	free_both(s2, s3);
	if (split[0] == NULL)
		return (free_split_ret_str(split, s4));
	if (split[1] == NULL)
		return (free_split_ret_str(split, s4));
	printf("\n\ngot to new token\n");
	printf("(*stc)->str = %s\n", (*stc)->str);
//	if ((*stc)->str)
//		free((*stc)->str);
	(*stc)->str = s4;
	printf("s4 : %s\n", (*stc)->str);
	return (new_token_env(stc, split, 1, new));
}*/


char	*if_no_env(char *str, int *i, char *s1)
{
	char	*new;
	char	*join;
	int		start;

	start = *i;
	while (str[(*i)] && str[(*i)] != '\'' && str[(*i)] != '"' && str[(*i)] != '$')
		(*i)++;
	new = malloc(sizeof(char) * ((*i) - start + 1));
	if (new == NULL)
		return (free_str_ret_null(s1));
	new = ft_strncpy(new, str + start, ((*i) - start));
	join = ft_strjoin(s1, new);
	free_both(s1, new);
	return (join);
}

char	*string_env(char *str, char *s1, int *i)
{
	char	*env;

	env = get_env(i, str);
	if (env)
		return (NULL);
	return (env);
}

char	*if_env(t_token **stc, char *str, char *s1, int *i)
{
	char	*env;
	char	**split;
	char	*join;

	env = string_env(str, s1, i);
	if (env == NULL)
		return (free_str_ret_null(s1));
	split = ft_strsplit(env, ' ');
	free(env);
	if (split == NULL)
		return (free_str_ret_null(s1));
	if (split[0] == NULL)
	{
		split[0] = malloc(sizeof(char));
		if (split[0] == NULL)
			return (free_str_ret_null(s1));
		split[0][0] = '\0';
	}
	join = ft_strjoin(s1, split[0]);
	free(s1);
	if (split[0] == NULL || split[1] == NULL)
		return (free_split_ret_str(split, join));
	(*stc)->str = join;
	return (new_token_env(stc, split, 1));
	
}

char	*word_till_unquote(t_token **stc, char *str, int *i, char *s1)
{
	int		start;

	start = *i;
	while (str[(*i)] && str[(*i)] != '\'' && str[(*i)] != '"')
	{
		if (str[(*i)] != '$')
		{
			s1 = if_no_env(str, i, s1);
			if (s1 == NULL)
				return (NULL);
		}
		else if (str[(*i)] && str[(*i)] == '$')
		{
			s1 = if_env(stc, str, s1, i);
			if (s1 == NULL)
				return (NULL);
		}
	}
	return (s1);
}

/*
char	*word_till_unquote(t_token **stc, char *str, int *i, char *s1)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = *i;
	while (str[(*i)] && str[(*i)] != '\'' && str[(*i)] != '"')
	{
		if (str[(*i)] == '$')
		{
			tmp = string_before_env(str, s1, i, j);
			if (tmp == NULL)
				return (NULL);
			printf("i avant get_env :%d\n", *i);
			tmp2 = string_env(str, tmp, i);
			printf("i apres get_env :%d\n", *i);
			if (tmp2 == NULL)
				return (NULL);
			s1 = env_unquote(stc, tmp2, tmp);
			j = *i + 1;
			printf("apres avoir trouve et prit l'env on en est a :%s, dans str\n", str+j);
			printf("apres avoir trouve et prit l'env on en est a :%s, dans str\n", str+(*i));

			//if (str[j] != '\0' && ft_is_alpha_num(str[j]) == 1 && str[j] != '_')// && str[j] != '$')
		}
		else
		{
			
			(*i)++;
		}
	}
	printf("entre dans word_end_unquote\n");
	return (end_word_unquote(str, s1, i, j));
}*/
