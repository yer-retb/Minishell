/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:08:33 by enja              #+#    #+#             */
/*   Updated: 2022/09/20 00:15:56 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parser_get(t_parser *st_list);

void	parser_check_command(t_token *st_list);

void	parser_scan_cmd(t_token *st_list);

void	parser_check_first_token(t_parser *st_list);

#endif