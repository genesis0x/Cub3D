/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:09:59 by hahadiou          #+#    #+#             */
/*   Updated: 2023/05/09 17:15:39 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_canvas    *mlx_load_img(void  *ptr, char *path)
{
    int         fd;
    t_canvas    *canvas;

    canvas = (t_canvas *)malloc(sizeof(t_canvas));
    canvas->img = NULL;
    if (!path || strncmp(path, ".xpm", 4))
        return (canvas);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (canvas);
    close(fd);
    canvas->img = mlx_xpm_file_to_image(ptr, path, &canvas->width, &canvas->height);
    canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bpp, &canvas->line_len, &canvas->endian);
    return (canvas);
}