#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

typedef struct Pair { int y, x; } Size, Cell;

typedef struct {
    size_t size, cap;
    Cell *live_cells;
} Pattern;

#endif
