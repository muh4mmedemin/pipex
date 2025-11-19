/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:38:36 by muayna            #+#    #+#             */
/*   Updated: 2025/11/19 16:38:36 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../error.h"

void check_arg_count(int argc)
{
    if(argc != 5)
    {
        ft_printf("Arg. count under 5 or upper 5 Fix it \n");
        exit(1);
    }
}