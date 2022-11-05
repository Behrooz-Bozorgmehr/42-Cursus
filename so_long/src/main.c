#include "./include/so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/
int main(int argc, char **argv)
{
  /*void	  *window;
  void    *mlx;
  t_data  data;

	mlx = mlx_init();
  window = mlx_new_window(mlx, 900, 700, "GAME ENVIRONMENT");
  data.img = mlx_new_image(mlx, 900, 700);
  data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
  //mlx_pixel_put(&data, window, 5+i, 5+i, 0x00ff0000);
  my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
  mlx_put_image_to_window(mlx,window,data.img, 0, 0);
  mlx_loop(mlx);*/

  //int open(const char *pathname, int flags);
  //int open(const char *pathname, int flags, mode_t mode);
  char    *file;
  t_data  data;
  t_map   map;
  data.map = &map;
  file = check_file_type(argc, argv);
  set_window(file, &data);
  //printf("file :%s\nwindow%dx%d\nmap%dx%d\n", file, data.width, data.height,map.w, map.h);
  create_map(file, &data);
  //printf("total: %d", data.tot_char);
  init_mlx(&data);
  render_win(&data);
  free(data.mlx);
  
  

  
  return (0);
}