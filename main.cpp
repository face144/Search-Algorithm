#include "Search.h"

int main() {
    Search a("test.txt", 1, 6);
    a.Start();
    delete &a;

    return 0;
}
