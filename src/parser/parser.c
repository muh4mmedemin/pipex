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

static void fill_input_file_name(t_token_list **list_pointer, char *input_file_name)
{
    (*list_pointer)->token_type = TOKEN_INPUT_FILE_NAME;
    (*list_pointer)->token = ft_split(input_file_name, ' ');
}

static void fill_out_file_name(t_token_list **list_pointer, char *out_file_name, int here_doc_checker)
{
    if (here_doc_checker == 3)
    {
        (*list_pointer)->token_type = HERE_DOC_OUT;
        (*list_pointer)->token = ft_split(out_file_name, ' ');
    }
    else
    {
        (*list_pointer)->token_type = TOKEN_OUTPUT_FILE_NAME;
        (*list_pointer)->token = ft_split(out_file_name, ' ');
    }
}

static void fill_command(t_token_list **list_pointer, char *command)
{
    (*list_pointer)->token_type = TOKEN_WORD;
    (*list_pointer)->token = ft_split(command, ' ');
}
static void fill_heredoc_limiter(t_token_list **list_pointer, char *command)
{
    (*list_pointer)->token_type = HERE_DOC_LIMITER;
    (*list_pointer)->token = ft_split(command, ' ');
}

static void fill_heredoc(t_token_list **list_pointer, char *command)
{
    (*list_pointer)->token_type = HERE_DOC;
    (*list_pointer)->token = ft_split(command, ' ');
}

t_token_list *fill_list(char **argv, char **envp)
{
    t_token_list *list;
    t_token_list *root;
    int i;

    list = ft_malloc(sizeof(t_token_list), 0);
    root = list;
    i = 1;
    while(argv[i])
    {
        if(i == 1 && !ft_strcmp(argv[i], "here_doc"))
            fill_heredoc(&list, argv[i]);
        else if (i == 2 && !ft_strcmp(argv[1], "here_doc"))
            fill_heredoc_limiter(&list, argv[i]);
        else if (i == 1)
            fill_input_file_name(&list, argv[i]);
        else if(argv[i + 1] != NULL)
            fill_command(&list, argv[i]);
        else if(argv[i + 1] == NULL)
            fill_out_file_name(&list, argv[i], root->token_type);
        list->next = ft_malloc(sizeof(t_token_list), 0);
        list = list->next;
        list->next = NULL;
        i++;
    }
    return root;
}
