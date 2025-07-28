#include <graphics.h>
#include <iostream>
using namespace std;

int maxX, maxY;
int originX, originY;


void drawAxes() {
    line(0, originY, maxX, originY); // X-axis
    line(originX, 0, originX, maxY); // Y-axis
}

struct Point {
    int x, y;
};

void drawTriangle(Point p1, Point p2, Point p3, int color = WHITE) {
    setcolor(color);
    // Convert Cartesian coordinates to screen coordinates
    line(originX + p1.x, originY - p1.y, originX + p2.x, originY - p2.y);
    line(originX + p2.x, originY - p2.y, originX + p3.x, originY - p3.y);
    line(originX + p3.x, originY - p3.y, originX + p1.x, originY - p1.y);
}

void translate(Point &p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    maxX = getmaxx();
    maxY = getmaxy();
    originX = maxX / 2;
    originY = maxY / 2;
    drawAxes();


    Point p1, p2, p3;
    cout << "Enter triangle vertices (x1 y1 x2 y2 x3 y3): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    drawTriangle(p1, p2, p3);

    int dx, dy;
    cout << "Enter translation factors dx and dy: ";
    cin >> dx >> dy;

    translate(p1, dx, dy);
    translate(p2, dx, dy);
    translate(p3, dx, dy);

    drawTriangle(p1, p2, p3, YELLOW);

    getch();
    closegraph();
    return 0;
}
