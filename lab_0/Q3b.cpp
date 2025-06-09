// Program to draw two concentric circles using graphics.h in C++

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = getmaxx() / 4;
    int yc = getmaxy() / 4;
    int radii[] = {90, 70};

    for (int i = 0; i < 2; i++) {
        circle(xc, yc, radii[i]);
    }


    getch();
    closegraph();
    return 0;
}
