# include "so_long.h"

int main(int argc, char **argv)
{
    int i = 1;
    t_map   *map;

    if (argc == 1)
        return (0);
    while (i < argc)
    {
        //printf("Empezando %d\n", i);
        map = get_map(argv[i]);
        free(map);
        i++;
    }
    return (0);
}