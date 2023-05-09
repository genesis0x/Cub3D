/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:11:40 by hahadiou          #+#    #+#             */
/*   Updated: 2023/05/09 19:15:09 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_map(t_data *data)
{
    int i;
    int j;
    int w;

    j = -1;
    while (++j < data->height)
    {
        w = ft_strlen(data->map[j]) - 1;
        i = 0;
        while (data->map[j][i] == ' ' && i < w)
            i++;
        while (data->map[j][w] == ' ' && w > 0)
            w--;
        if (strncmp(data->map[j], "", 1))
            ft_error(inv_map);
    }
}
