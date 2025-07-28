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
    line(originX + p1.x, originY - p1.y, originX + p2.x, originY - p2.y);
    line(originX + p2.x, originY - p2.y, originX + p3.x, originY - p3.y);
    line(originX + p3.x, originY - p3.y, originX + p1.x, originY - p1.y);
}

void drawPoint(Point p, int color = WHITE) {
    setcolor(color);
    circle(originX + p.x, originY - p.y, 3);
    setfillstyle(SOLID_FILL, color);
    floodfill(originX + p.x, originY - p.y, color);
}

// Translation function
void translate(Point &p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
}

// Pure scaling relative to origin
void scaleOrigin(Point &p, float sx, float sy) {
    p.x = p.x * sx;
    p.y = p.y * sy;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    maxX = getmaxx();
    maxY = getmaxy();
    originX = maxX / 2;
    originY = maxY / 2;
    drawAxes();
    
    Point p1, p2, p3, fixed;            
    float sx, sy;
    cout << "Enter triangle vertices (x1 y1 x2 y2 x3 y3): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << "Enter fixed point for scaling (xf yf): ";
    cin >> fixed.x >> fixed.y;
    cout << "Enter scaling factors sx and sy: ";
    cin >> sx >> sy;

    drawTriangle(p1, p2, p3, WHITE);
    
    // Mark the fixed point
    drawPoint(fixed, RED);
    
    // Step 1: Translate to origin (relative to fixed point)
    Point p1_t = p1, p2_t = p2, p3_t = p3;
    translate(p1_t, -fixed.x, -fixed.y);
    translate(p2_t, -fixed.x, -fixed.y);
    translate(p3_t, -fixed.x, -fixed.y);

    drawTriangle(p1_t, p2_t, p3_t, CYAN);

    outtextxy(10, 10, "Step 1: Translated to origin - Press any key");
    getch();
    
    // Step 2: Scale relative to origin
    Point p1_s = p1_t, p2_s = p2_t, p3_s = p3_t;
    scaleOrigin(p1_s, sx, sy);
    scaleOrigin(p2_s, sx, sy);
    scaleOrigin(p3_s, sx, sy);
    
    drawTriangle(p1_s, p2_s, p3_s, GREEN);

    outtextxy(10, 30, "Step 2: Scaled relative to origin");
    getch();
    
    // Step 3: Translate back
    Point p1_f = p1_s, p2_f = p2_s, p3_f = p3_s;
    translate(p1_f, fixed.x, fixed.y);
    translate(p2_f, fixed.x, fixed.y);
    translate(p3_f, fixed.x, fixed.y);

    drawTriangle(p1_f, p2_f, p3_f, YELLOW);

    outtextxy(10, 50, "Step 3: Translated back - Final result");
    
    getch();
    closegraph();
    return 0;
}
