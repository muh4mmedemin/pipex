/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:17:03 by muayna            #+#    #+#             */
/*   Updated: 2025/11/19 16:17:03 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

t_token_list *fill_list(char **argv, char **envp)
{
    t_token_list *list;
    t_token_list *root;
    int i;

    i = 1;
    list = ft_malloc(sizeof(t_token_list), 0);
    root = list;
    while(argv[i])
    {
        list->token = ft_split(argv[i], ' ');
        if(i == 1)
            list->token_type = TOKEN_INPUT_FILE_NAME;
        else if (i == 4)
            list->token_type = TOKEN_OUTPUT_FILE_NAME;
        else
            list->token_type = TOKEN_WORD;
        if(i != 4)
        {
            list->next = ft_malloc(sizeof(t_token_list), 0);
            list = list->next;
        }
        list->next = NULL;
        i++;
    }
    return root;
}
