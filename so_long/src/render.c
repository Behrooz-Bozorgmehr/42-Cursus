#include "./include/so_long.h"

/*int    key_value(int key)
{
    char c;
    
    c = key;
    write(1, &c, 1);
    write(1, "\n", 1);
    return (key);
}*/

void	render_win(t_data *data)
{
    mlx_hook(data->mlx_win, KEY_PRESSED, MASK, key_events, data);
	//mlx_key_hook(data->mlx_win, key_events, &data);
    mlx_loop(data->mlx);
}

     