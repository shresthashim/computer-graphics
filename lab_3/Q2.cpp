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
void plotEllipsePoints(int xc, int yc, int x, int y) {
    // 4-way symmetry
    drawPixel(xc + x, yc + y, WHITE);
    drawPixel(xc - x, yc + y, WHITE);
    drawPixel(xc + x, yc - y, WHITE);
    drawPixel(xc - x, yc - y, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, a, b;

    maxX = getmaxx();
    maxY = getmaxy();
    originX = maxX / 2;
    originY = maxY / 2;
    drawAxes();

    cout<<"Enter center (xc yc) and semi-axes a b: ";
    cin>>xc>>yc>>a>>b;

    int x = 0, y = b;
    double a2 = a*a, b2 = b*b;
    double p1 = b2 - a2*b + 0.25*a2;

    // Region 1
    while (b2*x <= a2*y) {
        plotEllipsePoints(xc, yc, x, y);
        x++;
        if (p1 < 0)
            p1 += 2*b2*x + b2;
        else {
            y--;
            p1 += 2*b2*x - 2*a2*y + b2;
        }
    }

    // Region 2
    double p2 = b2*(x + 0.5)*(x + 0.5) + a2*(y - 1)*(y - 1) - a2*b2;
    while (y > 0) {
        plotEllipsePoints(xc, yc, x, y);
        y--;
        if (p2 > 0)
            p2 -= 2*a2*y + a2;
        else {
            x++;
            p2 += 2*b2*x - 2*a2*y + a2;
        }
    }

    getch();
    closegraph();
    return 0;
}
