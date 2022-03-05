#include <iostream>
int recurse(int n) {
    printf("%d ", n);
    return recurse(n + 1);
}

int main()  {
    int n = 0;
    recurse(n);
}