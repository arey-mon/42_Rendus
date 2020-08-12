#include "../include/libft.h"
#include "../include/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	exit_clean(int err, t_game *g)
{
	char	**msg;
        printf("___ EXIT_CLEAN ___\n");
	ft_putstr_fd("Error\n", 1);
	msg = err_msg();
	ft_putstr_fd(msg[err], 1);
	exit(0);
	return (0);
}

char	**err_msg()
{
	char	**msg;
	printf("__ ERR_MSG __\n");
	if (!(msg = ft_calloc(sizeof(char *), 20)))
		return (NULL);
	msg[INV_FD] = "File is invalid\n";
	msg[INV_RES] = "Resolution is invalid\n";
	msg[INV_EXT] = "Extension is invalid\n";
	msg[INV_RGB] = "RGB is invalid\n";
	return (msg);
}

int	main(int ac, char **av)
{
	int	err;
	t_game	g;

	if (ac < 2 || (err = check_ext(av[1])))
		exit_clean(err, &g);
	get_settings(&g.set, open(av[1], O_RDONLY));
	err = parse_fd_check(&g.set);
	if (err > 0)
		exit_clean(err, &g);
	printf("err is : %d __ program finishing OK\n", err);
}
