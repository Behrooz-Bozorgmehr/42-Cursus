#ifndef SO_LONG_H
# define SO_LONG_H


// miniLibX
# include "../../minilibx_opengl/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
//open close file
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h> 
# include <unistd.h>

# include "../../libft/libft.h"
# include "../../getnextline/get_next_line.h"

// keys MacOS
# define ESC 53 
# define ENTER 36
# define SPACE 49

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_H 4
# define KEY_G 5
# define KEY_W 13
# define KEY_Q 12

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

// keys ASCII
# define ASC_LEFT 37
# define ASC_UP 38
# define ASC_RIGHT 39
# define ASC_DOWN 40
# define ASC_ENTER 13
# define ASC_SPACE 32
# define ASC_ESC 27

// some events MacOS  see https://harm-smits.github.io/42docs/libs/minilibx/events.html
# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define MOUSE_PRESSED 4
# define MOUSE_RELEASED 5
# define MOTION 6
# define WIN_CLOSED 17

# define MASK 0



# define IMG_HEIGHT 64
# define IMG_WIDTH 64
# define TITLE "SO_LONG"
# define EXIT 'E'
# define ENEMY 'A'
# define FILE_PATH "./map/"
# define STDERR 2
# define STDOUT 1

typedef struct s_map{
	char	**line;
	int		w;
	int		h;
}	t_map;

typedef struct s_img{ 
	void	*addr;
	int		endian;
	int		bpp;
	int		line_lenght;
	void	*background;	
	void	*object;
	void	*texture;
	void	*exit;
	void	*sprite;
	void	*s_up;
	void	*s_down;
	void	*s_left;
	void	*s_right;
}	t_img;

typedef struct s_data{ 
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		e_x;
	int		e_y;
	int		counter;
	int		collectibles;
	int		patrol;
	int		player;
	int		exit;
    int     fd;
    int     tot_char;
	int		key;
	t_img	*img;
	t_map	*map;
	//t_enem	*enem;
}	t_data;



void    *create(int x, int y, char *title);
void    getInput(int x, int y);
void    setComponents(char *str);
char    *getComponents();


char    *check_file_type(int argc, char **argv);
void    set_window(char *file, t_data	*data);
void	set_map_xy(int fd, t_map *map);
void	create_map(char	*file, t_data *data);
void	parse_map(t_data *data);
void	parse(t_data *data);
void	map_error(t_data *data, char *str);
void	parse_char(char c, t_data *data);
void	free_map(t_data *data);
void	*init_mlx(t_data *data);
void 	close_win(t_data *data);
void	move(t_data *data, char direction, int offset);
void	shoot(t_data *data);
void	next_level(t_data *data);
void	bleeding(t_data *data);
int		key_events(int key, t_data *data); // should be int func(int , *void) as defined in mlx.h => mlx_key_hook(), int func(*void, int) is not acceptable
void	render_win(t_data *data);
#endif /* SO_LONG_H */