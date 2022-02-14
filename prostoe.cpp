#include <iostream>
#include <math.h>

int prost (int a)
{
    int m = sqrt(a), j;
    for(j = 2; j <= m; j++) {
        if (a % j == 0) {
            return 0;
        }
        else if (j == m) return 1;
    }
}


int main() {
    int n, i, p;
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> p;
        printf("%d", prost(p), " ");
    }
}
