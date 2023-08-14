#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    int z;

    if (x > y) {
        z = x + y;
    } else {
        z = x - y;
    }

    // Dead code that will never be executed
    printf("This is dead code.\n");

    printf("z = %d\n", z);

    return 0;
}
