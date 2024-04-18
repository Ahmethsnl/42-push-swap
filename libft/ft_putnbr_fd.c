/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:46:59 by ahmsanli          #+#    #+#             */
/*   Updated: 2023/10/16 16:32:20 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_job(long nb, int *level, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		make_job(nb / 10, level, fd);
		make_job(nb % 10, level, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
		(*level)++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		level;
	long	nb;

	level = 0;
	nb = n;
	make_job(nb, &level, fd);
}
