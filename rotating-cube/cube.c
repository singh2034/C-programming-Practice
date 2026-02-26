#include <stdio.h>
#include <SDL2/SDL.h> //graphic library of C
#include <math.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define Color_white 0xffffffff
#define Color_black 0x00000000
#define POINT_SIZE 5
#define COORDINATE_SYSTEM_OFFSET_X SCREEN_WIDTH / 2
#define COORDINATE_SYSTEM_OFFSET_Y SCREEN_HEIGHT / 2

struct Point
{
    double x;
    double y;
    double z;
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

// matrix rotation for graphics
double phi = 5;

void apply_rotation(struct Point *point, double alpha, double beta, double gamma)
{
    double rotation_matrix[3][3] = {
        {cos(alpha) * cos(beta), cos(alpha) * sin(beta) * sin(gamma) - sin(alpha) * cos(gamma), cos(alpha) * sin(beta) * cos(gamma) + sin(alpha) * sin(gamma)},
        {sin(alpha) * cos(beta), sin(alpha) * sin(beta) * sin(gamma) + cos(alpha) * cos(gamma), sin(alpha) * sin(beta) * cos(gamma) - cos(alpha) * sin(gamma)},
        {-sin(beta), cos(beta) * sin(gamma), cos(beta) * cos(gamma)}};
    double point_vector[3] = {point->x, point->y, point->z};
    double result_point[3];
    for (int i = 0; i < 3; i++)
    {
        double dot_product = 0;
        for (int j = 0; j < 3; j++)
        {
            dot_product += rotation_matrix[i][j] * point_vector[j];
        }
        result_point[i] = dot_product;
    }
    point->x = result_point[0];
    point->y = result_point[1];
    point->z = result_point[2];
};

void initialize_cube(struct Point points[], int number_of_points)
{
    // int number_of_points = 100;
    // struct Point points[number_of_points];
    // cube has 12 sides
    int points_per_side = number_of_points / 12;

    int SIDE_LENGTH = 200;
    int step_size = SIDE_LENGTH / points_per_side;
    // side 1
    for (int i = 0; i < points_per_side; i++)
    {
        points[i] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                   -SIDE_LENGTH / 2, +SIDE_LENGTH / 2};
    }
    // side 2
    for (int i = 0; i < points_per_side; i++)
    {
        // mistake was here the number was big because of multiplication instead of addition
        points[i + points_per_side] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                                     SIDE_LENGTH / 2, +SIDE_LENGTH / 2};
    }
    // side 3
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 2 * points_per_side] = (struct Point){-SIDE_LENGTH / 2,
                                                         -SIDE_LENGTH / 2 + i * step_size, +SIDE_LENGTH / 2};
    }

    // side 4
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 3 * points_per_side] = (struct Point){SIDE_LENGTH / 2,
                                                         -SIDE_LENGTH / 2 + i * step_size, +SIDE_LENGTH / 2};
    }

    // side 5
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 4 * points_per_side] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                                         -SIDE_LENGTH / 2, -SIDE_LENGTH / 2};
    }
    // side 6
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 5 * points_per_side] = (struct Point){-SIDE_LENGTH / 2 + i * step_size,
                                                         SIDE_LENGTH / 2, -SIDE_LENGTH / 2};
    }
    // side 7
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 6 * points_per_side] = (struct Point){-SIDE_LENGTH / 2,
                                                         -SIDE_LENGTH / 2 + i * step_size, -SIDE_LENGTH / 2};
    }

    // side 8
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 7 * points_per_side] = (struct Point){SIDE_LENGTH / 2,
                                                         -SIDE_LENGTH / 2 + i * step_size, -SIDE_LENGTH / 2};
    }

    // side 9
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 8 * points_per_side] = (struct Point){-SIDE_LENGTH / 2,
                                                         -SIDE_LENGTH / 2, -SIDE_LENGTH / 2 + i * step_size};
    }

    // side 10
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 9 * points_per_side] = (struct Point){SIDE_LENGTH / 2,
                                                         -SIDE_LENGTH / 2, -SIDE_LENGTH / 2 + i * step_size};
    }

    // side 11
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 10 * points_per_side] = (struct Point){SIDE_LENGTH / 2,
                                                          SIDE_LENGTH / 2, -SIDE_LENGTH / 2 + i * step_size};
    }

    // side 12
    for (int i = 0; i < points_per_side; i++)
    {
        points[i + 11 * points_per_side] = (struct Point){-SIDE_LENGTH / 2,
                                                          SIDE_LENGTH / 2, -SIDE_LENGTH / 2 + i * step_size};
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
    SDL_Rect black_screen_rect = (SDL_Rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    int number_of_points = 1200;
    struct Point points[number_of_points];
    initialize_cube(points, number_of_points);
    draw_points_3d(surface, points, number_of_points);
    SDL_Event event;
    int simulation_running = 1;
    // double rotation_step = 0.01;
    double alpha = 0.01;
    double beta = 0.03;
    double gamma = 0.005;
    while (simulation_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                simulation_running = 0;
        }
        SDL_FillRect(surface, &black_screen_rect, Color_black);
        for (int i = 0; i < number_of_points; i++)
            apply_rotation(&points[i], alpha, beta, gamma);
        draw_points_3d(surface, points, number_of_points);

        SDL_UpdateWindowSurface(window);
        SDL_Delay(20);
    }
    // size of the shape & color of shape = white
    // SDL_Rect rect = (SDL_Rect){40, 40, 30, 60};
    // SDL_FillRect(surface, &rect, 0xffffffff);
    // Hold the window for 5 seconds
}
