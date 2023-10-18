#include "mlx.h"

#define MAP_WIDTH  10
#define MAP_HEIGHT 10
#define CELL_SIZE  50

// Example map data (using characters for simplicity)
char map_data[MAP_HEIGHT][MAP_WIDTH] = {
    "##########",
    "#........#",
    "#..##....#",
    "#..##....#",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "#........#",
    "##########"
};

int key_press(int keycode, void *param)
{
    if (keycode == 65)
    {

    }
}

void draw_map(void *mlx_ptr, void *win_ptr) {
    int x, y;

    // Loop through each cell of the map
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            // Calculate the position to draw the cell
            int draw_x = x * CELL_SIZE;
            int draw_y = y * CELL_SIZE;

            // Draw a rectangle for each cell based on map data
            if (map_data[y][x] == '#') {
                mlx_string_put(mlx_ptr, win_ptr, draw_x, draw_y, 0xFF0000, "#");  // Draw a red rectangle for walls
            } else if (map_data[y][x] == '.' && map_data[y][x] == 'T') {
                mlx_string_put(mlx_ptr, win_ptr, draw_x, draw_y, 0xFFFFFF, ".");  // Draw a white rectangle for open space
            }
            // Add more conditions for other elements in your map
        }
    }
}

int main(void) {
    void *mlx_ptr;
    void *win_ptr;

    // Initialize MiniLibX
    mlx_ptr = mlx_init();

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, MAP_WIDTH * CELL_SIZE, MAP_HEIGHT * CELL_SIZE, "Map Example");

    // Draw the map on the window
    mlx_string_put(mlx_ptr, win_ptr, 2 * CELL_SIZE, 2 * CELL_SIZE, 0xFF0000, "T");
    draw_map(mlx_ptr, win_ptr);

    
    // Start the event loop
    mlx_loop(mlx_ptr);

    return 0;
}
