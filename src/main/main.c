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
    check_arg_count(argc);
    t_token_list *list;
    list = fill_list(argv, envp);
    execve("/bin/ls", list->next->token, envp);
}