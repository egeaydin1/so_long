
# include "so_long.h"

int	main(int ac, char **av)
{
    if(!arg_check(ac, av))
		return (1);
	if (!map_main(av[1]))
		return (1);
	printf("map is valid\n");
    return 0;
}
