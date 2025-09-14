#include <iostream>
using namespace std;

void TowerHanoi(int n, char from, char des, char aulixiary) {
    // if only 1 disk, make the move and return
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, des);
        return;
    }
    // Move from A to B, using C as auxiliary
    TowerHanoi(n-1, from, aulixiary, des);
    printf("Move disk %d from peg %c to peg %c\n", n, from, des);
    // Move from B to C, using A as auxiliary
    TowerHanoi(n-1, aulixiary, des, from);
}

int main() {
    TowerHanoi(3, 'A', 'C', 'B');
}