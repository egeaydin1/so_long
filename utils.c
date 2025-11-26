#include "so_long.h"

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int error_return(char *str, int return_v)
{
	ft_printf("Error\n%s", str);
	return (return_v);
}

int arg_check(int ac, char **av)
{
    int fd;

	if (ac == 1)
		return (error_return("Map is missing.\n", 0));
	else if (ac > 2)
		return (error_return("Too many arguments.\n", 0));
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		return (error_return("Map file must have .ber extension.\n", 0));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
		return (error_return("Map file not found.\n", 0));
	return (1);
}

char **copy_map(char **map)
{
    char **copy;
    int i;

    i = 0;
    while (map[i])
        i++;
    
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy)
        return (NULL);
    
    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            ft_free_split(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}
