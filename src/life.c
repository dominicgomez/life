#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "conf.h"
#include "util.h"

Pattern gen_seed(Size size, double density)
{
    size_t cells = size.x * size.y;
    size_t live_cells = (int)(cells * density);
    Pattern seed;
    seed.live_cells = malloc(sizeof(Cell) * live_cells);
    seed.size = 0;
    seed.cap = live_cells;

    return seed;
}

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

        Size term_size = { LINES, COLS };
        Pattern seed = gen_seed(term_size, DENSITY);

        free(seed.live_cells);
    }

    resetty();
    endwin();

    return 0;
}
