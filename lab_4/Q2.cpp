#include <graphics.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#define PI 3.14159 

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

// Rotation around origin
void rotateOrigin(Point &p, float angle) {
    angle = angle * PI / 180;
    int x = p.x;
    int y = p.y;
    p.x = x * cos(angle) - y * sin(angle);
    p.y = x * sin(angle) + y * cos(angle);
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
    cout << "Enter triangle vertices (x1 y1 x2 y2 x3 y3): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << "Enter fixed point for rotation (xf yf): ";
    cin >> fixed.x >> fixed.y;

    float angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;

    drawTriangle(p1, p2, p3, WHITE);
    
    // Mark the fixed point
    drawPoint(fixed, RED);
    
    // Step 1: Translate to origin (relative to fixed point)
    Point p1_t = p1, p2_t = p2, p3_t = p3;
    translate(p1_t, -fixed.x, -fixed.y);
    translate(p2_t, -fixed.x, -fixed.y);
    translate(p3_t, -fixed.x, -fixed.y);
    
    drawTriangle(p1_t, p2_t, p3_t, CYAN);
    
    // Pause to see translation
    outtextxy(10, 10, "Step 1: Translated to origin - Press any key");
    getch();
    

    
    // Step 2: Rotate around origin
    Point p1_r = p1_t, p2_r = p2_t, p3_r = p3_t;
    rotateOrigin(p1_r, angle);
    rotateOrigin(p2_r, angle);
    rotateOrigin(p3_r, angle);
    
    drawTriangle(p1_r, p2_r, p3_r, GREEN);
    
    outtextxy(10, 30, "Step 2: Rotated around origin");
    getch();
    
    // Step 3: Translate back
    Point p1_f = p1_r, p2_f = p2_r, p3_f = p3_r;
    translate(p1_f, fixed.x, fixed.y);
    translate(p2_f, fixed.x, fixed.y);
    translate(p3_f, fixed.x, fixed.y);

    drawTriangle(p1_f, p2_f, p3_f, YELLOW);
    
    outtextxy(10, 50, "Step 3: Translated back - Final result");
    
    getch();
    closegraph();
    return 0;
}
