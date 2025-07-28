// MIDPOINT CIRCLE ALGORITHM IMPLEMENTATION
#include <graphics.h>
#include <iostream>
using namespace std;

int maxX, maxY;
int originX, originY;

void drawPixel(int x, int y, int color = WHITE) {
    putpixel(originX + x, originY - y, color);
    cout << "(" << x << "," << y << ")" << endl;
}

void drawAxes() {
    line(0, originY, maxX, originY); // X-axis
    line(originX, 0, originX, maxY); // Y-axis
}
void plotCirclePoints(int xc, int yc, int x, int y) {
    // 8-way symmetry
    drawPixel(xc + x, yc + y, WHITE);
    drawPixel(xc - x, yc + y, WHITE); 
    drawPixel(xc + x, yc - y, WHITE); 
    drawPixel(xc - x, yc - y, WHITE); 
    drawPixel(xc + y, yc + x, WHITE); 
    drawPixel(xc - y, yc + x, WHITE); 
    drawPixel(xc + y, yc - x, WHITE); 
    drawPixel(xc - y, yc - x, WHITE); 
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, r;
    
    maxX = getmaxx();
    maxY = getmaxy();
    originX = maxX / 2;
    originY = maxY / 2;
    drawAxes();
    
    cout<<"Enter center (xc yc) and radius r: ";
    cin>>xc>>yc>>r;

    int x = 0, y = r;
    double p = 1.25 - r;
    plotCirclePoints(xc, yc, x, y);

    while (x <= y) {
        x++;
        if (p < 0) {
            p += 2*x + 1;
        } else {
            y--;
            p += 2*(x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
    }

    getch();
    closegraph();
    return 0;
}

