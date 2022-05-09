#include <stdio.h>
#include "utils.h"

int delete(const char * filename) {
    if (remove(filename) == 0) {
        return 0;
    }
    return 1;
}
