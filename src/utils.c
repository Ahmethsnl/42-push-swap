/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:07:47 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/04/18 20:06:00 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_sorted_or_duplicate(t_data *data, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < data->a_size)
		{
			j = i + 1;
			while (j < data->a_size)
			{
				if (data->a[i] == data->a[j])
					free_n_exit(data, "Two same argument\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(data))
		free_n_exit(data, NULL);
}

void	parse_number(t_data *data)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	tmp = ft_split(data->join_args, ' ');
	i = 0;
	while (tmp[i])
	{
		data->a[j++] = f_atoi(tmp[i++], data);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	initialize_data(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->a_size = 0;
	data->b_size = 0;
	while (--ac)
	{
		if ((ft_count_words(av[i + 1], ' ')) != 0)
			data->a_size += ft_count_words(av[i + 1], ' ');
		else
			data->a_size++;
		i++;
	}
	data->a = malloc(data->a_size * sizeof * data->a);
	if (data->a == NULL)
		free_n_exit(data, "data->a not Allocate\n");
	data->b = malloc(data->a_size * sizeof * data->b);
	if (data->b == NULL)
		free_n_exit(data, "data->b not Allocate\n");
}

void	create_index(t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(data->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_n_exit(data, "new_a not Allocate\n");
	i = -1;
	while (++i < data->a_size)
	{
		k = 0;
		j = -1;
		while (++j < data->a_size)
			if (data->a[i] > data->a[j])
				k++;
		new_a[i] = k;
	}
	i = data->a_size;
	while (i--)
		data->a[i] = new_a[i];
	free(new_a);
}

int	f_atoi(const char *n, t_data *data)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_n_exit(data, "Atoi Error\n");
		res = res * 10 + (n[i++] - '0');
	}
	if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
		free_n_exit(data, "Atoi Error\n");
	return ((int)(res * sign));
}
