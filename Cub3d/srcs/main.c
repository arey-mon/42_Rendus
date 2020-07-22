#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <mlx.h>

char	**init_msg(void)
{
	char	**msg; 

	if (!(msg = ft_calloc(sizeof(char *), 14)))
		return (NULL);
	msg[NO_MAP] = "No map is specified";
	msg[WRONG_EXT] = "Extension is not .cub";
	return (msg);
}

int	clean_exit(int err, t_game *g)
{
	char	**msg; 
	(void)g; //will only be used to be freed
	ft_putstr_fd("Error\n", 1);
	msg = init_msg();
	ft_putstr_fd(msg[err], 1);
	free(msg);
	return (0);
}

int	check_ext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 1;
	while (str[i] == ' ')
		i--;
	if (str[i] == 'b' && str[i - 1] == 'u' && str[i - 2] == 'c' && str[i - 3] == '.')
	{
		//add check_file function here
		// if check_file == 1 >>> return (1)
		return (INV_CUB);
	}
	return (WRONG_EXT);
}

int	main(int ac, char **av)
{
	t_game	game;
	int 	err;

	if (ac < 2)
		clean_exit(NO_MAP, &game);
	else if ((err = check_ext(av[1])))
		clean_exit(err, &game);
	get_settings(&game.set, open(av[1], O_RDONLY));
}

