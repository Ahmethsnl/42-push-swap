/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:16:52 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/04/18 20:05:12 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char *str, int *arr, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_data *data)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (data->b_size <= 0)
			return ;
		tmp = data->b[0];
		ft_memmove(data->a + 1, data->a, sizeof(int) * data->a_size);
		data->a[0] = tmp;
		data->b_size--;
		ft_memmove(data->b, data->b + 1, sizeof(int) * data->b_size);
		data->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (data->a_size <= 0)
			return ;
		tmp = data->a[0];
		ft_memmove(data->b + 1, data->b, sizeof(int) * data->b_size);
		data->b[0] = tmp;
		data->a_size--;
		ft_memmove(data->a, data->a + 1, sizeof(int) * data->a_size);
		data->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *arr, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = arr[0];
		ft_memmove(arr, arr + 1, sizeof(int) * size - 1);
		arr[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = arr[size - 1];
		ft_memmove(arr + 1, arr, sizeof(int) * size - 1);
		arr[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
