#include "mlx.h"
#include <stdio.h>
#include <stddef.h>

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

// Structure to represent the position of the pixel
typedef struct {
    int x;
    int y;
} Pixel;

// Initial position of the pixel
Pixel pixel = {100, 100};

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

// Function to draw a white pixel at a given position
void draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y) {
    for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, 0xFFFFFF); // Draw a white pixel
}

void erase_pixel(void *mlx_ptr, void *win_ptr, int x, int y) {
    for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, 0x000000); // Draw a black pixel to "erase" the previous position
}

void *load_texture(void *mlx_ptr, char *filename, int *width, int *height) {
    return mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
}

void draw_texture(void *mlx_ptr, void *win_ptr, void *texture_img, int x, int y) {
    mlx_put_image_to_window(mlx_ptr, win_ptr, texture_img, x, y);
}
void erase_texture(void *mlx_ptr, void *win_ptr, void *texture_img, int x, int y) {
    mlx_put_image_to_window(mlx_ptr, win_ptr, texture_img, x, y);
}

// Key press event handler to move the pixel
int handle_key_press(int keycode, void *param) {
    // Update pixel position based on the pressed key

   erase_pixel(param, param, pixel.x, pixel.y);
    erase_texture(param, param, param, pixel.x, pixel.y);
    switch (keycode) {
        case 13: // Up Arrow
            pixel.y -= 1 * CELL_SIZE;
            printf("A\n");
            break;
        case 1: // Down Arrow
            pixel.y += 1 * CELL_SIZE;
            break;
        case 0: // Left Arrow
            pixel.x -= 1 * CELL_SIZE;
            break;
        case 2: // Right Arrow
            pixel.x += 1 * CELL_SIZE;
            break;
    }

    // Draw the updated pixel
   draw_pixel(param, param, pixel.x, pixel.y);
    draw_texture(param, param, param, pixel.x, pixel.y);
    return 0;
}

int main(void) {
    void *mlx_ptr;
    void *win_ptr;
 void *texture_img;
    int width, height;
    // Initialize MiniLibX
    mlx_ptr = mlx_init();

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Move Pixel Example");
    draw_map(mlx_ptr, win_ptr);
    texture_img = load_texture(mlx_ptr, "texture.xpm", 0, 0);

    draw_texture(mlx_ptr, win_ptr, texture_img, 100, 100);
    // Draw the initial pixel
    draw_pixel(mlx_ptr, win_ptr, pixel.x, pixel.y);

    // Register the key press event handler
    mlx_hook(win_ptr, 2, 1L << 0, &handle_key_press, win_ptr);

    // Start the event loop
    mlx_loop(mlx_ptr);

    return 0;
}
