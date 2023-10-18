#include "mlx.h"
#include <stdio.h>

void *load_texture(void *mlx_ptr, char *filename, int *width, int *height) {
    return mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
}

void draw_texture(void *mlx_ptr, void *win_ptr, void *texture_img, int x, int y) {
    mlx_put_image_to_window(mlx_ptr, win_ptr, texture_img, x, y);
}

int key_press(int keycode, void *param)
{
    // if (keycode == 0)
    //     printf("A\n");
    // else if (keycode == 1)
    //     printf("S\n");
    // else if (keycode == 2)
    //     printf("D\n");
    // else if (keycode == 13)
    //     printf("W\n");
    // else
    //     printf("%d\n", keycode);
    return keycode;
}

int main(void) {
    void *mlx_ptr;
    void *win_ptr;
    void *texture_img;
    int width, height;
    int key;

    // Initialize MiniLibX
    mlx_ptr = mlx_init();

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Texture Example");

    // Load texture
    texture_img = load_texture(mlx_ptr, "texture.xpm", &width, &height);

    // Draw texture on the window
    //draw_texture(mlx_ptr, win_ptr, texture_img, 100, 100);
    mlx_put_image_to_window(mlx_ptr, win_ptr, texture_img, 100, 100);
    
    mlx_hook(win_ptr, 2, 1L << 0, &key_press, NULL);
    // Start the event loop
    mlx_loop(mlx_ptr);

    return 0;
}
