/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:26:18 by enja              #+#    #+#             */
/*   Updated: 2022/11/03 19:01:01 by yer-retb         ###   ########.fr       */
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
void	delet_node(t_env **head, int pos);
void	list_at_back4(t_env **save, t_env *node);
void	builtins(t_env **env, t_data *data);
void	built_pwd(t_env *env);
void	built_env(t_env *envirement);
void	built_cd(t_env *envirement, char *str);
void	built_exit(char **str);
void	built_echo(char **str);
void	built_export(t_env *envirement, char **str);
void	built_unset(t_env **envirement, char **str);
int		check_file2(char *str);
int		check_file3(char *str);
void	execute(t_data data);
void	bash_builtin(t_data data, char **path);
char	**get_binary_file(t_env *env);
int		herdoc(char *str);
int		its_n(char *str);
int		ft_if_isalpha(char **str);
int		check_duplicate(t_env *envi, char **str);
void	delet_node(t_env **head, int pos);
int		check_string(char *str);

# endif
