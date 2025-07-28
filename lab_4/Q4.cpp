#include <graphics.h>
#include <iostream>
using namespace std;

int maxX, maxY;
int originX, originY;

struct Point {
    int x, y;
};

void drawAxes() {
    line(0, originY, maxX, originY); // X-axis
    line(originX, 0, originX, maxY); // Y-axis
}

void drawTriangle(Point p1, Point p2, Point p3, int color = WHITE) {
    setcolor(color);
    line(originX + p1.x, originY - p1.y, originX + p2.x, originY - p2.y);
    line(originX + p2.x, originY - p2.y, originX + p3.x, originY - p3.y);
    line(originX + p3.x, originY - p3.y, originX + p1.x, originY - p1.y);
}

// Shear with respect to X-axis (y = 0)
void shearX(Point &p, float shx) {
    p.x = p.x + shx * p.y;
    // y coordinate remains unchanged
}

// Shear with respect to Y-axis (x = 0)
void shearY(Point &p, float shy) {
    p.y = p.y + shy * p.x;
    // x coordinate remains unchanged
}

// Combined X and Y shearing
void shearXY(Point &p, float shx, float shy) {
    p.x = p.x + shx * p.y;
    p.y = p.y + shy * p.x;
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

    // Draw original triangle in white
    drawTriangle(p1, p2, p3, WHITE);
    
    int choice;
    cout << "Choose shearing type:" << endl;
    cout << "1. Shear with respect to X-axis" << endl;
    cout << "2. Shear with respect to Y-axis" << endl;
    cout << "3. Shear with respect to both axes" << endl;
    cin >> choice;

    float shx = 0, shy = 0;
    
    switch(choice) {
        case 1:
            cout << "Enter X-shearing factor (shx): ";
            cin >> shx;
            
            // Apply X-shearing
            shearX(p1, shx);
            shearX(p2, shx);
            shearX(p3, shx);

            drawTriangle(p1, p2, p3, CYAN);
            outtextxy(10, 10, "Shearing with respect to X-axis");
            break;
            
        case 2:
            cout << "Enter Y-shearing factor (shy): ";
            cin >> shy;
            
            // Apply Y-shearing
            shearY(p1, shy);
            shearY(p2, shy);
            shearY(p3, shy);

            drawTriangle(p1, p2, p3, GREEN);
            outtextxy(10, 10, "Shearing with respect to Y-axis");
            break;
            
        case 3:
            cout << "Enter X-shearing factor (shx): ";
            cin >> shx;
            cout << "Enter Y-shearing factor (shy): ";
            cin >> shy;
            
            // Apply both shearing transformations
            shearXY(p1, shx, shy);
            shearXY(p2, shx, shy);
            shearXY(p3, shx, shy);

            drawTriangle(p1, p2, p3, YELLOW);
            outtextxy(10, 10, "Shearing with respect to both axes");
            break;
            
        default:
            cout << "Invalid choice!" << endl;
    }

    getch();
    closegraph();
    return 0;
}