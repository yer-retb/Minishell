/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:48:16 by enja              #+#    #+#             */
/*   Updated: 2022/11/10 22:39:14 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct n_red
{
	int				type;
	int				fd;
	char			*file;
	struct n_red	*next;
}				t_red;

typedef struct n_data
{
	char	**str;
	t_red	*red;
	int		in;
	int		out;
	int		size;
	int		flag;
}	t_data;

t_data	big_data(t_psr *node);
void	make_data(t_bige_node *bignode);
int		node_size(t_bige_node *bignode);
int		check_file(char *str);
int		check_file2(char *str);

#endif
