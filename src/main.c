/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:25:58 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/04/18 19:50:19 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_n_exit(t_data *data, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (data)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		if (data)
			free(data);
	}
	exit(1);
}

static void	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		free_n_exit(NULL, "enter at least 2 arguments");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || argv[i][0] == ' ')
			free_n_exit(NULL, "Argument not valid\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_n_exit(NULL, "Argument not valid\n");
			j++;
		}
	}
}

static void	join_args(int ac, char **av, t_data *data)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < ac && av[1])
	{
		tmp = ft_strjoin(tmp2, av[i]);
		if (tmp2)
			free(tmp2);
		if (i != ac -1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	data->join_args = ft_strdup(tmp);
	if (data->join_args == NULL)
		free_n_exit(data, "Argument Alocate Error\n");
	if (tmp)
		free(tmp);
}

int	main(int ac, char **av)
{
	t_data	*data;

	validate_args(ac, av);
	data = malloc(sizeof * data);
	if (!data)
		exit(1);
	initialize_data(ac, av, data);
	join_args(ac, av, data);
	parse_number(data);
	exit_sorted_or_duplicate(data, 0);
	create_index(data);
	if (data->a_size == 2 && data->a[0] > data->a[1])
		swap("sa", data->a, data->a_size);
	else if (data->a_size == 3)
		sort_three(data);
	else if (data->a_size >= 4 && data->a_size <= 5)
		sort_four_to_five(data);
	else
		radix_sort(data);
	exit_sorted_or_duplicate(data, 1);
	free_n_exit(data, "Error\n");
}
