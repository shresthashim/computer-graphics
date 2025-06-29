// Bresenham's Line Drawing Algorithm in C++

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int maxX, maxY;
int originX, originY;

// Function to plot a point in cartesian coordinates
void drawPixelCartesian(int x, int y, int color = WHITE)
{
    putpixel(originX + x, originY - y, color);
}

void drawAxes()
{
    line(0, originY, maxX, originY); // X-axis
    line(originX, 0, originX, maxY); // Y-axis
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x1, y1, x2, y2, dx, dy, p, i, incx, incy, x, y;

    maxX = getmaxx();
    maxY = getmaxy();
    originX = maxX / 2;
    originY = maxY / 2;
    drawAxes();

    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    dx = x2 - x1;
    dy = y2 - y1;

    incx = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
    incy = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);

    dx = abs(dx);
    dy = abs(dy);

    x = x1;
    y = y1;

    // Choose which algorithm to use based on slope
    if (dx > dy)
    {
        // When |dx| > |dy| - increment along x-axis
        p = 2 * dy - dx;

        for (i = 0; i < dx; i++)
        {
            if (p < 0)
            {
                x += incx;
                p += 2 * dy;
            }
            else
            {
                x += incx;
                y += incy;
                p += 2 * (dy - dx);
            }
            drawPixelCartesian(x, y, WHITE);
            delay(10);
        }
    }
    else
    {
        // When |dy| >= |dx| - increment along y-axis
        p = 2 * dx - dy;

        for (i = 0; i < dy; i++)
        {
            if (p < 0)
            {
                y += incy;
                p += 2 * dx;
            }
            else
            {
                x += incx;
                y += incy;
                p += 2 * (dx - dy);
            }
            drawPixelCartesian(x, y, WHITE);
            delay(10);
        }
    }

    getch();
    closegraph();
    return 0;
