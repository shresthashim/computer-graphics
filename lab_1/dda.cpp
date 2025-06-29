// DDA Line Drawing Algorithm in C++

#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

void DDA(int x1, int y1, int x2, int y2)
{
    float xi, yi, x, y, steps;
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (abs(dx) >= abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    xi = dx / steps;
    yi = dy / steps;
    x = x1, y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        x += xi;
        y += yi;
        delay(10);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    DDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
