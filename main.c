#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'

char picture[HEIGHT][WIDTH];
void clearPicture() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            picture[i][j] = EMPTY;
        }
    }
}

void displayPicture() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
}

void setPixel(int x, int y) {
    if(x >= 0 && x < WIDTH &&
       y >= 0 && y < HEIGHT) {
        picture[y][x] = PIXEL;
    }
}
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps;

    if(dx > dy)
        steps = dx;
    else
        steps = dy;

    float xIncrement = (float)(x2 - x1) / steps;
    float yIncrement = (float)(y2 - y1) / steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        setPixel((int)(x + 0.5), (int)(y + 0.5));

        x += xIncrement;
        y += yIncrement;
    }
}
void drawRectangle(int x1, int y1, int x2, int y2)
{
    drawLine(x1, y1, x2, y1); // Top
    drawLine(x1, y2, x2, y2); // Bottom
    drawLine(x1, y1, x1, y2); // Left
    drawLine(x2, y1, x2, y2); // Right
}
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void drawCircle(int cx, int cy, int radius)
{
    int angle;

    for(angle = 0; angle < 360; angle++)
    {
        double rad = angle * 3.14159265 / 180.0;

        int x = cx + (int)(radius * cos(rad));
        int y = cy + (int)(radius * sin(rad));

        setPixel(x, y);
    }
}

