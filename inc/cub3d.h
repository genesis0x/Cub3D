/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:02:02 by hahadiou          #+#    #+#             */
/*   Updated: 2023/05/09 19:03:09 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <ctype.h>

typedef struct  s_parse     t_parse;
typedef struct  s_data      t_data;
typedef struct  s_mlx       t_mlx;
typedef struct  s_cam       t_cam;
typedef struct  s_canvas    t_canvas;
typedef struct  s_textures  t_textures;
typedef struct  s_list      t_list;
typedef struct  s_color     t_color;
typedef enum    e_error     t_error;

enum    e_error
{
    end,
    inv_ac,
    empty_file,
    inv_file,
    inv_ext,
    inv_map
};

struct  s_list
{
    void    *content;
    t_list  *next;
};

struct  s_color
{
    long    t;
    long    r;
    long    g;
    long    b;    
};

struct s_parse
{
    int     fd;
    char    **map;
    t_error error;
};

struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
};

// struct						s_cam
// {
// 	float					mu;
// 	float					alpha;
// 	float					d;
// 	float					fx;
// 	float					fy;
// 	t_point					tr;
// 	t_point					ro;
// 	t_vectors				v;
// 	t_point					**coords;
// };

struct						s_canvas
{
	//t_point					p;
	int			width;
	int			height;
	void					*img;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
};

struct                      s_textures
{
    t_list  *north;
    t_list  *south;
    t_list  *west;
    t_list  *east;
    int     floor;
    int     ceiling;
};

struct s_data
{
    int         fd;
    char        **map;
    int         height;
    int         width;
    t_mlx       mlx;
    t_canvas    canvas;
    t_textures  textures;
    //t_cam   cam[1];
};

/**********************************/
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int 	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *s, char ,int i, int j);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int     array_length(char **arr);
char	**extend_matrix(char **in, char *newstr);
int     cub_atoi(char *nptr, long *nbr);
int     create_trgb(t_color c);
void	get_cf_color(char **arr, t_data *data);
/**********************************/

void    check(int ac, char **av);
void    init_data(t_data *data);
void    ft_error(t_error error);
void    read_map(char *filename, t_data *data);
void    get_cf_color(char **arr, t_data *data);

/***************************************************************/
t_canvas    *mlx_load_img(void  *ptr, char *path);
/***************************************************************/
#endif
