/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:26:18 by enja              #+#    #+#             */
/*   Updated: 2022/10/24 14:40:52 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILLTINS_H
# define BUILLTINS_H

typedef struct n_env
{
	char			*name;
	char			*path;
	struct n_env	*next;
}	t_env;

t_env	*envirement_list(char **env);
t_env	*init_env1(char **str);
void	list_at_back4(t_env **save, t_env *node);
void	builtins(t_env **env, t_data *data);
void	built_pwd(t_env **env);
void	built_cd(t_env **env, char *str);
int		check_file2(char *str);
void	execute(t_data data);

# endif
