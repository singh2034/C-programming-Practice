#include <stdio.h>
#include <SDL2/SDL.h> //graphic library of C

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define Color_white 0xffffffff
#define POINT_SIZE 5
#define COORDINATE_SYSTEM_OFFSET_X SCREEN_WIDTH / 2
#define COORDINATE_SYSTEM_OFFSET_Y SCREEN_HEIGHT / 2

struct Point
{
    int x;
    int y;
    int z;
};

int draw_point(SDL_Surface *surface, int x, int y)
{
    // size of the shape & color of shape = white
    SDL_Rect rect = (SDL_Rect){x, y, POINT_SIZE, POINT_SIZE};
    SDL_FillRect(surface, &rect, Color_white);
}

int draw_point_3d(SDL_Surface *surface, struct Point point)
{
    int x_2d = point.x + COORDINATE_SYSTEM_OFFSET_X;
    int y_2d = point.y + COORDINATE_SYSTEM_OFFSET_Y;
    draw_point(surface, x_2d, y_2d);
}

int draw_points_3d(SDL_Surface *surface, struct Point points[], int number_of_points)
{

    for (int i = 0; i < number_of_points; i++)
    {
        int x_2d = points[i].x + COORDINATE_SYSTEM_OFFSET_X;
        int y_2d = points[i].y + COORDINATE_SYSTEM_OFFSET_Y;
        draw_point(surface, x_2d, y_2d);
    }
}

void initialize_cube(struct Point points[], int number_of_points)
{
    // int number_of_points = 100;
    // struct Point points[number_of_points];

    // cube has 12 sides
    int points_per_side = number_of_points / 12;

    int SIDE_LENGTH = 50;
    int step_size = SIDE_LENGTH / points_per_side;
    // side 1
    for (int i = 0; i < points_per_side; i++)
    {
        points[i] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                   -SIDE_LENGTH / 2, +SIDE_LENGTH / 2};
    }

    // side 2
    for (int i = points_per_side; i < 2 * points_per_side; i++)
    {
        points[i] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                   -SIDE_LENGTH / 2, +SIDE_LENGTH / 2};
    }
    // side 3
    for (int i = 2 * points_per_side; i < 3 * points_per_side; i++)
    {
        points[i] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                   -SIDE_LENGTH / 2, +SIDE_LENGTH / 2};
    }
    
    // return points;
}

int main()
{
    // Intialize a Window
    SDL_Init(SDL_INIT_VIDEO);

    // Parameters to set it to centre of the screen and give the size.
    SDL_Window *window = SDL_CreateWindow("3D Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    // struct Point point = {0, 0, 0};
    int number_of_points = 120;
    struct Point points[number_of_points];
    initialize_cube(points, number_of_points);
    draw_points_3d(surface, points, number_of_points);

    // size of the shape & color of shape = white
    // SDL_Rect rect = (SDL_Rect){40, 40, 30, 60};
    // SDL_FillRect(surface, &rect, 0xffffffff);

    SDL_UpdateWindowSurface(window);

    // Hold the window for 5 seconds
    SDL_Delay(5000);
}
