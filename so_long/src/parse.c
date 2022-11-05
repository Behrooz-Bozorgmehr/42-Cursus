#include "./include/so_long.h"

char	*check_file_type(int argc, char **argv)
{
   	char *file;
    
	file = NULL;
	if (argc < 2)
	{
		ft_putendl_fd("Error\nUnsufficient Argument, Map cannot be searched", STDERR);
		exit(1);
	}
    else if (argc > 2)
		ft_putendl_fd("More than one file path, only first file path is being evaluated", STDOUT);
    file = ft_strjoin(FILE_PATH, argv[1]);
	file = ft_strjoin(file, ".ber");
	if (ft_strnstr(file, ".ber", ft_strlen(file)) == NULL)
	{	
		ft_putendl_fd("Error\nFile type is not correct (*.ber)", STDERR);
		exit(1);
	}
    return (file);
}

//set window size from input file & img size
void set_window(char *file, t_data	*data)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
	{
		ft_putendl_fd("Error\nMap_path not found", STDERR);
		exit(1);
	}
	set_map_xy(data->fd, data->map);
	data->width = data->map->w * IMG_WIDTH;
	data->height = data->map->h * IMG_HEIGHT;
	close(data->fd);
}

// set map size from input file
// map area of file should finish by a null char and not a new line.
// Otherwise following method would need modification. This can also assure 
// less care on file endings
void	set_map_xy(int fd, t_map *map)
{
	char	c;
	
	map->w = 0;
	map->h = 0;
	while (read(fd, &c, 1))
	{
		if (c != '\n' && map->h == 0)
			map->w++;
		else if (c == '\n')
			map->h++;
	}
	if (map->h)
		map->h++;
}



//set map's elements
void	create_map(char	*file, t_data *data)
{
	int	i;
	
	i = -1;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return ;
	data->map->line = (char **)malloc(sizeof(char *) * (data->map->h + 1));
	if (data->map->line == NULL)
	{
		ft_putendl_fd("Error\nMemory allocation failed", STDERR);
		exit(1);
	}
	while (++i < data->map->h)
		data->map->line[i] = get_next_line(data->fd);
	data->map->line[i] = NULL;
	parse_map(data);
}

void	parse_map(t_data *data)
{
	data->player = 0;
	data->exit = 0;
	data->patrol = 0;
	data->collectibles = 0;
	parse(data);
	if (data->map->w == data->map->h)
		map_error(data, "The map is not rectangular");
	else if (data->collectibles == 0)
		map_error(data, "No object to collect");
	else if ((data->player != 1 || data->exit != 1) || data->patrol > 1)
		map_error(data, "Only one 'Player', 'Exit' and 'Patrol' is permitted");
}
//read char par char and define each element of map
//total char permit to know if there is any irregularity in lines
//as map area of file terminates with a null char and not a new line
//1 is added to total value at the end.
void	parse(t_data *data)
{
    int r;
    int c;
	
    r = 0;
	data->tot_char = 0;
	while (data->map->line[r] != NULL)
	{
		c = 0;
		while (data->map->line[r][c])
		{	
			if ((r == 0 || r == data->map->h - 1) && (data->map->line[r][c] != '1' && data->map->line[r][c] != '\n'))
				map_error(data, "Horizontal wall is not built correctly");
			else if ((c == 0 || c == data->map->w - 1) && (data->map->line[r][c] != '1' && data->map->line[r][c] != '\n'))
				map_error(data, "Vertical Wall is not built correctly");
			parse_char(data->map->line[r][c], data);
			c++;
		}
		data->tot_char += c;
		r++;
    }
	data->tot_char = data->tot_char  - r + 1;
}
 
void	map_error(t_data *data, char *str)
{
	free_map(data);
    ft_putendl_fd("Error", STDERR);
	ft_putendl_fd(str, STDERR);
	exit(1);
}

void	parse_char(char c, t_data *data)
{
	if (c == 'P')
		data->player++;
	else if (c == 'E')
		data->exit++;
	else if (c == 'R')
		data->patrol++;
	else if (c == 'C')
		data->collectibles++;
    else if (c != '1' && c != '0' && c != '\n')
		map_error(data, "Invalid character in the Map");
}

void	free_map(t_data *data)
{
	while (*(data->map->line))
	{
		free(*(data->map->line));
        *(data->map->line) = NULL;
		data->map->line++;
	}
	data->map->line = NULL;
}