/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:26:18 by enja              #+#    #+#             */
/*   Updated: 2022/10/23 10:53:40 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILLTINS_H
# define BUILLTINS_H

void	builtins(char **env, t_data *data);
void	built_pwd(char **env);
void	built_cd(char **env, char *str);

# endif
