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

<<<<<<< HEAD
void execute_heredoc(t_token_list **list, char **envp)
{
    char *str;
    int fd;
    (*list) = (*list)->next;
=======
void execute_heredoc(t_token_list **list, char **envp, char *here_doc_limiter)
{
    int fd;
    char *str;
// value coming with \n or \r\n in console, cut it, after thart compare ft_strcmp
    fd = open("test.txt", O_RDONLY, 0777);
    str = get_next_line(fd);
    printf("%d\n", strcmp(str, here_doc_limiter));
>>>>>>> c5235be (fixed ft_strcmp)

}

int main(int argc, char *argv[], char **envp)
{
    int i;

    i = 0;
    t_token_list *list;

    //check_arg_count(argc);
    list = fill_list(argv, envp);
<<<<<<< HEAD
=======
    execute_heredoc(&list, envp, list->next->token[0]);
>>>>>>> c5235be (fixed ft_strcmp)
    /*if(list->token_type == 3)
        execute_heredoc(&list, envp);
    else
        create_path(&list, envp);

    ft_malloc(1, 1);*/
}
