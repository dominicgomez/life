#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "conf.h"
#include "util.h"

int main()
{
    srand(time(NULL));

    initscr();
    savetty();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    if (has_colors()) {
        start_color();
        use_default_colors();
    }

    int keypress;
    while(true) {
        keypress = getch();
        if (keypress == 'q') {
            break;
        }

        size_t coords = (size_t)(LINES * COLS) * DENSITY;

        for (size_t i = 0; i < coords; ++i) {
        }
    }

    resetty();
    endwin();

    return 0;
}
