/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:00:38 by muayna            #+#    #+#             */
/*   Updated: 2025/11/14 10:44:17 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# define COLOR_GREEN "\e[0;32m"
# define COLOR_BGRN "\e[1;32m"
#define C_RST "\e[0;0m"

//take arguments "FileName "ls -a""

typedef enum s_special_token{
	PIPE = '|',
	IN_REDURECT = '<',
	OUT_REDURECT = '>'
} t_special_token;

typedef enum {
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDURECT
} Tokentype;

typedef struct s_option
{
    char *option;
    struct s_option *next;
} t_option;

typedef struct s_token{
    char **argv;
	Tokentype type;
    struct s_token *next;
} t_token;

char *get_token_option(char *input, int size)
{
	char *token;
	int i;
	i = 0;
	token = malloc(size + 1);
	token[size] = '\0';
	while(input[i] != '|' && input[i])
	{
		token[i] = input[i];
		i++;
	}
	return token;
}

void fill(char *input, char **envp)
{
	char *cmd;
	t_token *list;
	t_token *root;
	int i = 0;
	int b = 0;
	int c = 0;
	list = malloc(sizeof(t_token));
	root = list;
	while(input[i])
	{
		if(input[i] == '|')
		{
			cmd = get_token_option(input + b, i - b);
			list->argv = ft_split(cmd, ' ');
			list->type = TOKEN_WORD;
			list->next = malloc(sizeof(t_token));
			list = list->next;
			list->argv = NULL;
			list->type = TOKEN_PIPE;
			list->next = malloc(sizeof(t_token));
			list = list->next;
			b = i + 1;
		}
		i++;
	}
	if(input[i] == '\0')
	{
		cmd = get_token_option(input + b, i - b);
		list->argv = ft_split(cmd, ' ');
		list->type = TOKEN_WORD;
		list->next = NULL;
	}
	int f = 0;
	while(root)
	{
		f = 0;
		while(root->argv && root->argv[f])
		{
			printf("%s", root->argv[f]);
			f++;
		}
		root = root->next;
	}
	
}

int main(int argc, char *argv[],  char **envp)
{
	char *input;
	while(1)
   	{
		input = readline(COLOR_BGRN "Babashell" C_RST "$ ");
		fill(input, envp);
	}
}
