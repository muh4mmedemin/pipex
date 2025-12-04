/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:25:12 by muayna            #+#    #+#             */
/*   Updated: 2025/12/02 16:25:12 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    if(s1 == NULL && s2 == NULL)
        return 0;
    if(s1 == NULL || s2 == NULL)
        return 1;
    while(s1[i] && s2[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0')
    {
        return 0;
    }
    return 1;
}
