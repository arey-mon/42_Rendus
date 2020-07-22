#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void		init_fc(t_settings *set)
{
        if (!(set->rgb_f = (int*)malloc(sizeof(int) * 3)))
                return ;
        if (!(set->rgb_c = (int*)malloc(sizeof(int) * 3)))
                return ;
}

void	get_map(t_settings *set, int fd, char *str)
{
        char    *s2;

        s2 = NULL;
        str = ft_strjoin_free_dest(str, "\n");
        while (get_next_line(fd, &s2))
        {
                s2 = ft_strjoin_free_dest(s2, "\n");
                str = ft_strjoin_free(str, s2);
        }
        if (*s2 != '\n')
                str = ft_strjoin_free(str, s2);
        set->map = ft_split(str, '\n');
        free(str);
}

void		get_settings(t_settings *set, int fd)
{
	char	*str;

	(void)fd;
	str = NULL;
	init_fc(set);
	// str = fill_fields
	get_map(set, fd, str);
}
