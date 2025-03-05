/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:14:14 by rjoseph           #+#    #+#             */
/*   Updated: 2025/01/10 17:03:00 by rjoseph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    initialize_struct(t_oken **cmd, int c)
{
    *cmd = (t_oken *)malloc(c * sizeof(t_oken));
    if (*cmd == NULL)
        exit (-1);
}