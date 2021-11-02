/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <lchristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:43:14 by lchristo          #+#    #+#             */
/*   Updated: 2021/11/01 16:43:19 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structures.h"
# include "libft.h"

/* -------------------------------------------------------------------------- */
/*                   FILE = src/built_in/ft_built_in_pwd.c                    */
/* -------------------------------------------------------------------------- */
int    ft_built_in_pwd(void);

/* -------------------------------------------------------------------------- */
/*                   FILE = src/built_in/ft_built_in_echo.c                   */
/* -------------------------------------------------------------------------- */
int     ft_check_n(char **str);
void    ft_built_in_echo(char **str);

/* -------------------------------------------------------------------------- */
/*                   FILE = src/built_in/ft_built_in_env.c                    */
/* -------------------------------------------------------------------------- */
void ft_built_in_env(void);
int     ft_is_equal(char *str);
void	ft_built_in_show_env(t_env **env);

/* -------------------------------------------------------------------------- */
/*                    FILE = src/built_in/ft_delete_key.c                     */
/* -------------------------------------------------------------------------- */
int		ft_delete_env(char *str);
void	ft_delete_env_call(t_env **env, char *key);

/* -------------------------------------------------------------------------- */
/*                  FILE = src/built_in/ft_env_singletone.c                   */
/* -------------------------------------------------------------------------- */
int		ft_get_lenkey(char *env);
int		ft_singletone(char *str, int mode);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/built_in/ft_add_value.c                     */
/* -------------------------------------------------------------------------- */
int		ft_add_env(char *str);
int		ft_add_value_to_env(t_env **env_list, char *env);

/* -------------------------------------------------------------------------- */
/*                    FILE = src/built_in/ft_push_front.c                     */
/* -------------------------------------------------------------------------- */
int		ft_push_front(char *env, t_env **begin_lst);

/* -------------------------------------------------------------------------- */
/*                  FILE = src/built_in/ft_built_in_export.c                  */
/* -------------------------------------------------------------------------- */
void    ft_built_in_show_export(void);
int		ft_built_in_export(char **str);
void	ft_show_export(t_env **env);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/built_in/ft_init_env.c                      */
/* -------------------------------------------------------------------------- */
t_env	**get_adress_env(void);
int		ft_init_t_env(char **env);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/built_in/ft_free_env.c                      */
/* -------------------------------------------------------------------------- */
void	ft_clean_env(void);
void	ft_clean_envlist(t_env **env);
void	ft_free_env_elem(t_env *env);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/built_in/ft_get_value.c                     */
/* -------------------------------------------------------------------------- */
char	*ft_get_env(char *str);
char	*ft_get_value_of_env(t_env **env, char *str);

/* -------------------------------------------------------------------------- */
/*                  FILE = src/built_in/ft_built_in_unset.c                   */
/* -------------------------------------------------------------------------- */
void    ft_built_in_unset(char **str);

/* -------------------------------------------------------------------------- */
/*                      FILE = src/parsing/expend_word.c                      */
/* -------------------------------------------------------------------------- */
int	word_modif_two(t_token *stc, char *str, e_quote quote, e_quote prec);
int	word_modif(t_token *stc, char *str, e_token token);
int	edit_type(t_commande_line **block);
int	check_open_fil(t_commande_line **block);
int	expend_word(t_commande_line **block);

/* -------------------------------------------------------------------------- */
/*                        FILE = src/parsing/parsing.c                        */
/* -------------------------------------------------------------------------- */
e_quote	update_quote_status(char c, e_quote quote);
e_quote	update_quote_succes(t_token *stc, int *i, e_quote quote);
int	unclose_quote(char	*str);

/* -------------------------------------------------------------------------- */
/*                   FILE = src/parsing/env_extend_or_not.c                   */
/* -------------------------------------------------------------------------- */
char	*envp_unchange(int *i, char *str, char *word);

/* -------------------------------------------------------------------------- */
/*                   FILE = src/parsing/word_till_double.c                    */
/* -------------------------------------------------------------------------- */
char	*env_doublequote(char *str, char *s1, int *i, int j);
char	*word_till_double(char *str, int *i, char *s1);

/* -------------------------------------------------------------------------- */
/*                        FILE = src/parsing/limitor.c                        */
/* -------------------------------------------------------------------------- */
int	limitor(t_token *stc, char *str);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/parsing/get_cmd_line.c                      */
/* -------------------------------------------------------------------------- */
void	get_pipe(int *i, char *str);
void	init_cmdl(t_commande_line *new);
int	get_new_cmdl(char *str, int i, int j, t_commande_line **first);
void	add_envp_to_cmdl(t_commande_line **first, char **envp);
int	get_cmd_line(char *string, t_commande_line **first, char **envp);

/* -------------------------------------------------------------------------- */
/*                        FILE = src/parsing/get_env.c                        */
/* -------------------------------------------------------------------------- */
int	get_len_env_var(char *str);
int	is_env(char *str, char *env, int len);
char	*alloc_dollar(void);
char	*get_envp(char *str, int *j);
char	*get_env(int *cur, char *str);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/parsing/parsing_utils.c                     */
/* -------------------------------------------------------------------------- */
int	is_separator(char c);
int	is_redirection(char c);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/parsing/organise_arg.c                      */
/* -------------------------------------------------------------------------- */
void	init_arg(t_commande_line *cmd);
int	nbr_arg_cmd(t_commande_line *cmd);
int	organise_arg(t_commande_line **cmd);

/* -------------------------------------------------------------------------- */
/*                    FILE = src/parsing/add_new_test_2.c                     */
/* -------------------------------------------------------------------------- */
char	*free_split_ret_str(char **split, char *str);
char	*new_token_env(t_token **stc, char **split, int i);
char	*env_unquote(t_token **stc, char *s2, char *s3);
char	*if_no_env(char *str, int *i, char *s1);
char	*string_env(char *str, char *s1, int *i);
char	*if_env(t_token **stc, char *str, char *s1, int *i);
char	*word_till_unquote(t_token **stc, char *str, int *i, char *s1);
char	*word_till_unquote(t_token **stc, char *str, int *i, char *s1);

/* -------------------------------------------------------------------------- */
/*                      FILE = src/parsing/init_token.c                       */
/* -------------------------------------------------------------------------- */
void	init_token(t_token *new);
void	init_type(t_token *new);

/* -------------------------------------------------------------------------- */
/*                   FILE = src/parsing/word_till_single.c                    */
/* -------------------------------------------------------------------------- */
char	*word_till_single(char *str, int *i, char *s1);

/* -------------------------------------------------------------------------- */
/*                   FILE = src/parsing/devellipe_limitor.c                   */
/* -------------------------------------------------------------------------- */
int	move_to(char *str, int *i, e_quote quote);
char	*limitor_unquote(char *str, int *i, char *s1, e_quote quote);
char	*expand_full_quote_str(void);
char	*devellope_limitor(t_token *stc, char *str, int i);
int	limitor(t_token *stc, char *str);

/* -------------------------------------------------------------------------- */
/*                       FILE = src/parsing/split_arg.c                       */
/* -------------------------------------------------------------------------- */
int	get_new_arg(int *i, int *j, char *str);
int	add_new_token(int i, int j, char *str, t_commande_line **stc);
void	iter_to_end_or_redirection(char	*str, int *i);
int	split(t_commande_line **stc);
int	split_arg(t_commande_line **first);

/* -------------------------------------------------------------------------- */
/*                      FILE = src/parsing/free_utils.c                       */
/* -------------------------------------------------------------------------- */
int	free_cmdl_ret_malloc_error(t_commande_line *stc);
int	free_token_ret_malloc_error(t_token *tok);
char	*free_str_ret_null(char *s1);
void	free_both(char *s1, char *s2);
void	free_split(char **split);

/* -------------------------------------------------------------------------- */
/*                       FILE = src/parsing/fake_env.c                        */
/* -------------------------------------------------------------------------- */
char	*copy_fake_env(char *str);
char	*fake_env(int *j, int len_str);
int	len_fake_env(char *str);


#endif
