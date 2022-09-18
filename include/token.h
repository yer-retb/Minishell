/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:15:58 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/18 22:52:54 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct n_token
{
	enum
	{
		TOKEN_STR,
		TOKEN_PIPE,
		TOKEN_IN,
		TOKEN_OUT,
		TOKEN_HRDOC,
		TOKEN_APPEND,
		TOKEN_FLAG,
	} e_type;
	char	*value;
}	t_token;

t_token	*init_token(int e_type, char *value);

#endif
