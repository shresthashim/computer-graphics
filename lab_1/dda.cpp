#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

int maxX, maxY;
int originX, originY;

// Function to plot a point in cartesian coordinates
void drawPixelCartesian(int x, int y, int color = WHITE) {
    putpixel(originX + x, originY - y, color);
}

// Function to draw axes
void drawAxes() {
    // X-axis
    line(0, originY, maxX, originY);
    // Y-axis
    line(originX, 0, originX, maxY);
}

// Modified DDA function for Cartesian coordinates
void DDA(int x1, int y1, int x2, int y2) {
    float xi, yi, x, y, steps;
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    xi = dx / steps;
    yi = dy / steps;
    
    x = x1;
    y = y1;

    for (int i = 0; i <= steps; i++) {
        drawPixelCartesian(round(x), round(y));
        x += xi;
        y += yi;
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    maxX = getmaxx();
    maxY = getmaxy();
    originX = maxX / 2;
    originY = maxY / 2;

    drawAxes();

    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;

    DDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}