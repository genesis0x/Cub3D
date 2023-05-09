/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:05:55 by hahadiou          #+#    #+#             */
/*   Updated: 2023/05/09 18:40:10 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_data  *data;

    data = (t_data *)malloc(sizeof(t_data));
    //bzero(data, sizeof(data));
    check(ac, av);
    init_data(data);
    read_map(av[1], data);
    return (0);
}
