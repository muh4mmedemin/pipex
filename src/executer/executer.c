/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:05:01 by muayna            #+#    #+#             */
/*   Updated: 2025/11/19 16:05:01 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"
//Old just read, new just write
static void command_to_outfile_for_norm2(int fd, int *pipefd, int *pipefd2, char **c)
{
    dup2(fd, 1);
    dup2(pipefd[0], 0);
    close(fd);
    close(pipefd2[1]);
    close(pipefd2[0]);
    close(pipefd[1]);
    close(pipefd[0]);
    execve("/bin/cat", c, NULL);
    exit(0);
}

static void command_to_outfile_for_norm(int fd, int *pipefd, int *pipefd2, char **c)
{
    dup2(fd, 1);
    dup2(pipefd2[0], 0);
    close(fd);
    close(pipefd[1]);
    close(pipefd[0]);
    close(pipefd2[1]);
    close(pipefd2[0]);
    execve("/bin/cat", c, NULL);
    exit(0);
}

static void command_to_outfile(t_token_list ***list, int checker, int *pipefd, int *pipefd2)
{
    int fd;

    fd  = open((**list)->token[0], O_RDWR | O_CREAT | O_TRUNC, 0777);
    pid_t pid;
    char *c[4];

    c[0] = "cat";
    c[1] = NULL;
    pid = fork();
    if(pid == 0)
    {
        if(checker == 0)
            command_to_outfile_for_norm2(fd, pipefd, pipefd2, c);
        else
            command_to_outfile_for_norm(fd, pipefd, pipefd2, c);
    }
    close(pipefd[0]);
    close(pipefd2[0]);
    close(pipefd[1]);
    close(pipefd2[1]);
    close(fd);
}

static void run_command(t_token_list ***list, char **envp, int *old_pipefd, int *new_pipefd)
{
    pid_t pid;

    close(old_pipefd[1]);
    pid = fork();
    if(pid == 0)
    {
        dup2(old_pipefd[0], 0);
        dup2(new_pipefd[1], 1);
        close(old_pipefd[0]);
        close(new_pipefd[0]);
        close(new_pipefd[1]);
        execve(ft_strjoin("/bin/", (**list)->token[0]), (**list)->token, envp);
        perror("Error : ");
        exit(0);
    }
    pid = wait(NULL);
    close(old_pipefd[0]);
    (**list) = (**list)->next;
    pipe(old_pipefd);
}

static void input_pipe_command(t_token_list ***list, char **envp, int *pipefd)
{
    pid_t pid;
    int fd;

    fd = open((**list)->token[0], O_RDONLY, 0777);
    pid = fork();
    if(pid == 0)
    {
        dup2(fd, 0);
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);
        close(fd);
        execve(ft_strjoin("/bin/", (**list)->next->token[0]), (**list)->next->token, envp);
        exit(0);
    }
    close(fd);
    (**list) = (**list)->next;
    pid = wait(NULL);
    return ;
}


void create_path(t_token_list **list, char **envp)
{
    int pipefd[2];
    int pipefd2[2];
    int checker;

    checker = 0;
    pipe(pipefd);
    pipe(pipefd2);
    while((*list)->token_type != 2)
    {
        if ((*list)->token_type == 1)
            input_pipe_command(&list, envp, pipefd);
        else if ((*list)->token_type == 0 && checker == 0)
        {
            checker = 1;
            run_command(&list, envp, pipefd, pipefd2);
        }
        else if ((*list)->token_type == 0 && checker == 1)
        {
            checker = 0;
            run_command(&list, envp, pipefd2, pipefd);
        }
        if((*list)->token_type == 2)
            command_to_outfile(&list, checker, pipefd, pipefd2);
    }
}
