/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:16:50 by laltarri          #+#    #+#             */
/*   Updated: 2024/01/22 19:06:37 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	while (++i < argc)
	{
		e = 0;
		j = ft_strlen(argv[i]);
		if (argv[i][0] == '-' || argv[i][0] == '+')
			e++;
		while (e < j)
		{
			if (!(argv[i][e] >= '0' && argv[i][e] <= '9'))
				return (0);
			e++;
		}
	}
	return (1);
}

t_list	*arrstr_to_arrint(int argc, char **argv)
{
	long long	num;
	t_list		*nums;
	t_list		*tem;
	int			i;

	nums = NULL;
	tem = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_lstclear(&nums), NULL);
		tem = ft_lstnew(num);
		if (!tem)
			return (ft_lstclear(&nums), NULL);
		ft_lstadd_back(&nums, tem);
		i++;
	}
	return (nums);
}

int	contnum(char *str)
{
	int	i;
	int	contador;

	i = 0;
	contador = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-' || str[0] == '+')
		{
			contador++;
			while (str[i + 1] != '\0' && str[i + 1] != '-' && str[i + 1] != '+')
			{
				i++;
				contador++;
			}
		}
		i++;
	}
	return (contador);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	int		i;

	i = 0;
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	if (check_argv(argc, argv) == 0 || !a
		|| !b || check_duplicate(argc, argv) == 0)
		return (ft_puterror());
	while (i < argc)
	{
		if (contnum(argv[i]) > 12)
			return (ft_puterror());
		i++;
	}
	*a = arrstr_to_arrint(argc, argv);
	index_stack(a);
	if (ft_lstsize(*a) < 6)
		simple_short(a, b);
	else
		radix_sort(a, b);
	ft_lstclear(a);
	return (0);
}
