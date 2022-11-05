#include "./include/so_long.h"

void    *create(int x, int y, char *title)
{
    void    *mlx;
    void    *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, x, y, title);

    mlx_loop(mlx);
    return (window);
}

void    *init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, TITLE);
 //OK   mlx_string_put(data->mlx, data->mlx_win, 100, 100, 0x00ffffff,"here");
    return (data->mlx_win);
}

void close_win(t_data *data)
{
   ft_putendl_fd("in close_win", STDOUT);
    mlx_destroy_window(data->mlx, data->mlx_win);
   // mlx_destroy_display(data->mlx);
    free_map(data);
    free(data->mlx);
    //free(data->mlx_win);
    exit(0);
}

int    key_events(int key, t_data *data)
{
    ft_putendl_fd("in key_events", STDOUT);
    if (key == ESC || key  == KEY_Q)
        close_win(data);
    else if (key == UP || key == KEY_W)
        move(data, 'Y', -1);
    else if (key == DOWN || key == KEY_S)
        move(data, 'Y', 1);
    else if (key == RIGHT || key == KEY_D)
        move(data, 'X', 1);
    else if (key == LEFT || key == KEY_A)
        move(data, 'X', -1);
 //   else if (key == SPACE)
 //       shoot(data);
 //   if (data->map->line[data->pos_x][data->pos_y] == EXIT)
 //       next_level(data);
 //   if (data->map->line[data->pos_x][data->pos_y] == ENEMY)
 //       bleeding(data);
    return (0);
}

void    move(t_data *data, char direction, int offset)
{
    ft_putendl_fd(&direction, STDOUT);
    if (direction == 'X' && data->map->line[data->pos_x + offset][data->pos_y] != 1)
        data->pos_x += offset; 
    else if (direction == 'Y' && data->map->line[data->pos_x][data->pos_y + offset] != 1)
        data->pos_y += offset; 
}

//end of game at this point.
void    next_level(t_data *data)
{
    if (data->collectibles == 0)
        close_win(data);
}
/*
void    shoot(t_data *data)
{
    //
}
*/