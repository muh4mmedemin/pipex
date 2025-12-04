/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:05:43 by muayna            #+#    #+#             */
/*   Updated: 2025/06/21 18:59:14 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*final;
	void	*content;

	if (lst == NULL || del == NULL || f == NULL)
		return (NULL);
	final = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, new);
		new = new->next;
		lst = lst->next;
	}
	return (final);
}
