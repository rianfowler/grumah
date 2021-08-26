/* map.h by burlapjack 2021
 * 
 */

#ifndef MAP_H
#define MAP_H

char* map_init(char *map, int map_width, int map_height);

void map_generate_srp(char *map, int map_width, int map_height, int room_size_max, int room_size_min, int num_rooms);
#endif /* MAP_H */
