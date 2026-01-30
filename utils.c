/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   simple.c                                           :+:      :+:    :+:   */
=======
/*   utils.c                                            :+:      :+:    :+:   */
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:17:35 by sla-gran          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/21 11:17:35 by sla-gran         ###   ########.fr       */
=======
/*   Updated: 2026/01/29 11:49:43 by sla-gran         ###   ########.fr       */
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
void simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*temp;
	int		value;

	temp = *stack_a;
	value = INT_MIN;
	while (temp->next)
	{
		if (value > temp->content)
			return (0);
		value = temp->content;
		temp = temp->next;
	}
}

void	free_stack(t_list stack_a)
=======
void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stack(t_list **stack)
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

<<<<<<< HEAD
void	ft_free()
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
=======
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1
}
