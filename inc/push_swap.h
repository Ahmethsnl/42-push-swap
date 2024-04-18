/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:40:13 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/04/18 20:06:18 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}	t_data;

void	rotate(int *array, int size, char *direction, char *list);
void	swap(char *str, int *array, int size);
void	push(char *str, t_data *data);
void	sort_three(t_data *data);
void	sort_four_to_five(t_data *data);
void	radix_sort(t_data *data);
void	parse_number(t_data *data);
void	create_index(t_data *data);
void	initialize_data(int argc, char **argv, t_data *data);
void	free_n_exit(t_data *data, char *msg);
void	exit_sorted_or_duplicate(t_data *data, int i);
int		is_array_sorted(t_data *data);
int		f_atoi(const char *n, t_data *data);

#endif