/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:45:10 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 22:50:56 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define TRUE			1
# define TOKEN_STR 		0
# define TOKEN_PIPE		1
# define TOKEN_IN		2
# define TOKEN_OUT		3
# define TOKEN_HRDOC	4
# define TOKEN_APPEND	5
# define TOKEN_FLAG		6

char	*get_prompt(void);
void	clear_prompt(void);
int		is_rederection(char c);
void	msg_error(void);
#endif