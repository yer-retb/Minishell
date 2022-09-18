/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:48:31 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/19 00:14:55 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_token	*init_token(int e_type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->e_type = e_type;
	token->value = value;
	return (token);
}
