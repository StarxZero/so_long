#include "so_long.h"

int is_mouse_inside_button(int x, int y, Button button) {
    return (x >= button.position.x && x <= button.position.x + button.width &&
            y >= button.position.y && y <= button.position.y + button.height);
}

void draw_button(void *mlx_ptr, void *win_ptr, Button button, int is_mouse_over) {
    int color;
    if (is_mouse_over == 1)
        color = 0x00FF00;
    else
        color = 0xFF0000;
    mlx_string_put(mlx_ptr, win_ptr, button.position.x, button.position.y, color, "Click me!");
}

int handle_mouse_click(int button, int x, int y, void *param) {
    Button *button_ptr = (Button *)param;

    if (button == 1) {  // Assuming left mouse button (button 1) for simplicity
        if (is_mouse_inside_button(x, y, *button_ptr)) {
            printf("Button clicked!\n");
            // Add your button click logic here
        }
    }

    return 0;
}

int handle_mouse_move(int x, int y, void *param) {
    Button *button_ptr = (Button *)param;

    int is_mouse_over = is_mouse_inside_button(x, y, *button_ptr);

    // Clear previous button state
    draw_button(param, param, *button_ptr, 0);

    // Draw the button with the updated state
    draw_button(param, param, *button_ptr, is_mouse_over);

    return 0;
}

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    Button mybutt;
    mybutt.position.x = 50;
    mybutt.position.y = 50;
    mybutt.width = 100;
    mybutt.height = 50;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 720, 480, "testing");
    draw_button(mlx_ptr, win_ptr, mybutt, 0);
    mlx_mouse_hook(win_ptr, &handle_mouse_click, &mybutt);
    mlx_hook(win_ptr, 6, 1L << 6, &handle_mouse_move, &mybutt);
    mlx_loop(mlx_ptr);

    return (0);
}