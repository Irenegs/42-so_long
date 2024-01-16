
# include "so_long.h"

void pinta_info(t_map *map)
{
	printf("Num char: %d\n", map->info.num_char);
	printf("Cells: %d\n", map->info.cells);
	printf("Columns: %d\n", map->info.columns);
	printf("Lines %d\n", map->info.lines);
	printf("Position: %d\n", map->info.position);
	printf("Collectables: %d\n", map->info.collectables);
	printf("Exit: %d\n", map->info.exit);
}