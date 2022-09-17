/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:48:31 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 05:36:43 by enja             ###   ########.fr       */
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
