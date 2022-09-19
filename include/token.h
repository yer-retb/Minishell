/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:15:58 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/19 09:19:20 by ky05h1n          ###   ########.fr       */
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
