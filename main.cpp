#include "Search.h"

int main() {
    Search a("teste.txt", 1, 6);
    a.Start();
    delete &a;

    return 0;
}
