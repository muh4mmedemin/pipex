/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:48:56 by muayna            #+#    #+#             */
/*   Updated: 2025/12/04 21:48:56 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char  *cut_wrong_chracter(const char *s1)
{
    int i;
    int size;
    char *new_str;

    i = 0;
    if (s1 == NULL || !ft_strchr(s1, '\n'))
        return (char *)s1;
    while (s1[i] && (s1[i] != '\n' && s1[i] != '\r'))
        i++;
    new_str = ft_malloc(i + 1, 0);
    i = 0;
    while(s1[i] && (s1[i]!= '\n' && s1[i] != '\r'))
    {
        new_str[i] = s1[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}
