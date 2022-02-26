#include "Search.h"

int main() {
    Search a("test.txt");
    a.BreathFirstSearch(1);
    system("pause");
    a.DepthFirstSearch(1);
    system("pause");
    delete &a;


    return 0;
}
