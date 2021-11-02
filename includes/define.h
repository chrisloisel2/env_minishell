/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <lchristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:49:08 by lchristo          #+#    #+#             */
/*   Updated: 2021/11/02 14:16:17 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

typedef	enum mod
{
	GET,
	DELETE,
	FREE,
	ADD
}			e_mod;

typedef enum token
{
	NON,
	ARG,
	BUILTIN,
	OPEN_FILE,
	HERE_DOC,
	LIMITOR,
	CREAT_FILE,
	WRITE_FILE,
	FILE_IN,
	FILE_OUT,
	FILE_OUT_OVER,
	ENDS
}				e_token;


typedef enum quote
{
	NONE,
	SINGLE,
	DOUBLE,
	BACKSLASH,
	END
}	e_quote;

#endif