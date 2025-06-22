#include <stdio.h>
#include <graphics.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    int i, maxx, midy;

    initgraph(&gd, &gm, "X:\\TC\\BGI");
    maxx = getmaxx();
    midy = getmaxy() / 2;

    for (i = 0; i < maxx - 150; i = i + 5) {
        cleardevice();

        // Draw road
        setcolor(WHITE);
        line(0, midy + 37, maxx, midy + 37);

        // Draw Rickshaw body
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);

        // Main body outline (tall back, curved front)
        line(i, midy + 23, i, midy - 25);           // Tall back
        line(i, midy - 25, i + 40, midy - 25);      // Top of cabin
        line(i + 40, midy - 25, i + 80, midy - 10); // Curved front top
        line(i + 80, midy - 10, i + 100, midy);     // Windshield slope
        line(i + 100, midy, i + 100, midy + 23);    // Front vertical
        
        // Base with wheel wells
        line(i, midy + 23, i + 18, midy + 23);
        arc(i + 30, midy + 23, 0, 180, 12);  // Rear wheel well
        line(i + 42, midy + 23, i + 78, midy + 23);
        arc(i + 90, midy + 23, 0, 180, 12);  // Front wheel well
        line(i + 102, midy + 23, i + 100, midy + 23);
        
        // Cabin details
        line(i + 20, midy - 25, i + 20, midy - 5);  // Cabin divider
        line(i + 20, midy - 5, i + 40, midy - 5);   // Seat base
        
        // Fill body
        floodfill(i + 5, midy - 10, YELLOW);
        
        // Draw Wheels
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, DARKGRAY);
        circle(i + 30, midy + 25, 9);  // Rear wheel
        circle(i + 90, midy + 25, 9);  // Front wheel
        floodfill(i + 30, midy + 25, BLUE);
        floodfill(i + 90, midy + 25, BLUE);

        delay(100);
    }

    closegraph();
    return 0;
}