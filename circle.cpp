#include<graphics.h>

int main(){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Draw a circle with center at (200, 200) and radius 100
    circle(200, 200, 100);

    // Wait for a key press
    getch();

    // Close the graphics window
    closegraph();
    return 0;
}