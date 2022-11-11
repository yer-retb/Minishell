/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:48:31 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/11 00:18:35 by yer-retb         ###   ########.fr       */
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
