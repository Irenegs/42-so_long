# include "so_long.h"

int main(int argc, char **argv)
{
    int i = 1;
    t_mapinfo map;

    if (argc == 1)
        return (0);
    while (i < argc)
    {
        printf("Empezando %d\n", i);
        printf("%d: %d\n", i-1, check_map(argv[i], &map));
        i++;
    }
    return (0);
}