/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:58:02 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 02:30:32 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

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
void	built_env(t_env *envirement, int fd);
void	built_cd(t_env *envirement, char *str);
void	built_exit(char **str);
void	built_echo(char **str, int fd);
void	built_export(t_env *envirement, char **str, int fd);
void	built_unset(t_env **envirement, char **str);
char	*check_command(char **files, char *cmd);
int		check_path(char *str);
int		scan_path(char *cmd);
void	execute(t_data data);
void	bash_builtin(t_data data, char **path, int *prosid);
char	**get_binary_file(t_env *env);
int		herdoc(char *str);
int		excut_herdoc(t_data *data);
int		its_n(char *str);
int		ft_if_isalpha(char **str);
int		check_duplicate(t_env *envi, char **str);
void	delet_node(t_env **head, int pos);
int		check_string(char *str);
void	get_file_descr(t_data *data);
void	export_print_error(char *str);
void	swap(int *a, int *b);
void	ft_excut_cmd(t_data data, char **path);
void	close_files(void);
void	ft_is_directory(char *cmd);
void	print_is_directory(char *cmd);

#endif