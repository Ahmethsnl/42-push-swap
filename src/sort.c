/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:59:40 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/04/18 20:05:57 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_data *data)
{
	if (data->a[2] != 2)
	{
		if (data->a[0] == 2)
			rotate(data->a, data->a_size, "up", "a");
		else
			rotate(data->a, data->a_size, "down", "a");
	}
	if (data->a[0] > data->a[1])
		swap("sa", data->a, data->a_size);
}

void	sort_four_to_five(t_data *data)
{
	while (data->b_size <= 1)
	{
		if (data->a[0] == 0 || data->a[0] == 1)
			push("pb", data);
		else
			rotate(data->a, data->a_size, "up", "a");
	}
	if (data->b[0] == 0)
		swap("sb", data->b, data->b_size);
	if (data->a[2] != 4)
	{
		if (data->a[0] == 4)
			rotate(data->a, data->a_size, "up", "a");
		else
			rotate(data->a, data->a_size, "down", "a");
	}
	if (data->a[0] > data->a[1])
		swap("sa", data->a, data->a_size);
	push("pa", data);
	push("pa", data);
}

int	is_array_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a_size - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_sort_stack_b(t_data *data, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(data))
	{
		if (((data->b[0] >> j) & 1) == 0)
			rotate(data->b, data->b_size, "up", "b");
		else
			push("pa", data);
	}
	if (is_array_sorted(data))
		while (data->b_size != 0)
			push("pa", data);
}

void	radix_sort(t_data *data)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = data->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = data->a_size;
		while (size-- && !is_array_sorted(data))
		{
			if (((data->a[0] >> j) & 1) == 0)
				push("pb", data);
			else
				rotate(data->a, data->a_size, "up", "a");
		}
		radix_sort_stack_b(data, data->b_size, bit_size, j + 1);
	}
	while (data->b_size != 0)
		push("pa", data);
}
