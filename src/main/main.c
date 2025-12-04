/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:20:41 by muayna            #+#    #+#             */
/*   Updated: 2025/11/19 16:20:41 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void execute_heredoc(t_token_list **list, char *here_doc_limiter)
{
    int fd;
    char *str;
    char *exit_character;

    exit_character = NULL;
    fd = open(TEMP_FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0777);
    while(1)
    {
        str = get_next_line(0);
        exit_character = cut_wrong_chracter(str);
        if(ft_strcmp(here_doc_limiter, exit_character))
            write(fd, str, ft_strlen(str));
        else
        {
            free(str);
            break ;
        }
        free(str);
    }
    (*list) = (*list)->next;
    (*list)->token_type = TOKEN_INPUT_FILE_NAME;
    (*list)->token = ft_split(TEMP_FILE_NAME, ' ');
    close(fd);
    return ;
}

int main(int argc, char *argv[], char **envp)
{
    int i;

    i = 0;
    t_token_list *list;

    //check_arg_count(argc);
    list = fill_list(argv, envp);
    if(list->token_type == 3)
        execute_heredoc(&list, list->next->token[0]);
    create_path(&list, envp);
    unlink(TEMP_FILE_NAME);
    ft_malloc(1, 1);
}
