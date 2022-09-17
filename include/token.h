/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:15:58 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 22:46:42 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct n_token
{
	enum
	{
		TOKEN_STR,
		TOKEN_CMD,
		TOKEN_PIPE,
		TOKEN_INPUT,
		TOKEN_OUTPUT,
		TOKEN_LL,
		TOKEN_GG,
		TOKEN_SINGLE_Q,
		TOKEN_DOUBLE_Q,
		TOKEN_DOLER,
		TOKEN_FLAG,
	} e_type;
	char	*value;
}	t_token;

t_token	*init_token(int e_type, char *value);

#endif
