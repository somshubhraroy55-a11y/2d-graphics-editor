#include <stdio.h>
#include <stdlib.h>

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
