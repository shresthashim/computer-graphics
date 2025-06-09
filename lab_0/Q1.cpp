// Program to display "WRC" in decreasing font sizes using graphics.h

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100, y = 100;
    
    for (int i = 0; i < 3; i++) {
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3 - i); // size 3, 2, 1
        outtextxy(x, y + i * 50, "WRC");
    }

    getch();
    closegraph();
    return 0;
}
