// Purpose: Draw lines and a pixel in a graphics window using the graphics.h library in C++.

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    line(0, 0, 250, 250);

    line(50, 75, 480, 570);

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;
    putpixel(midX, midY, WHITE);

    getch();
    closegraph();

    return 0;
}
