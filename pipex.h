/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:01:11 by muayna            #+#    #+#             */
/*   Updated: 2025/11/19 16:01:11 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h> // Delete
#include <string.h> // Delete
#include "libs/ft_printf/ft_printf.h"
#include "libs/libft/libft.h"
#include "libs/garbage_collector/gb.h"
#include "libs/get_next_line/get_next_line.h"
#include "error.h"

#define TEMP_FILE_NAME ".secret"

typedef enum s_type
{
    TOKEN_WORD,
    TOKEN_INPUT_FILE_NAME,
    TOKEN_OUTPUT_FILE_NAME,
    HERE_DOC,
    HERE_DOC_LIMITER,
    HERE_DOC_OUT
} t_type;

typedef struct s_token_list
{
    char **token;
    t_type token_type;
    struct s_token_list *next;
} t_token_list;

t_token_list *fill_list(char **argv, char **envp);
void create_path(t_token_list **list, char **envp);
char  *cut_wrong_chracter(const char *s1);

#endif