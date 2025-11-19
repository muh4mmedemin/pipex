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

int main(int argc, char *argv[], char **envp)
{
    pid_t pid;
    int pipefd[2];
    t_token_list *list;

    check_arg_count(argc);
    list = fill_list(argv, envp);
    pipe(pipefd);
    pid = fork();
    if (pid == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);
        execve(ft_strjoin("/bin/", list->next->token[0]), list->next->token, envp);
        return 1;
    }
    pid = fork();
    if(pid == 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        close(pipefd[0]);
        execve(ft_strjoin("/bin/", list->next->next->token[0]), list->next->next->token, envp);
        return 1;
    }
    wait(NULL);
}