#include <iostream>

int polindrom(int a)
{
    int b = a, k = 1, mirra = 0, c;
    while (b > 0) {
        c = b % 10;
        b = b / 10;
        mirra = mirra + k * c;
        k = k * 10;
    }
    if (mirra == a) return 1;
    else return -1;
}


int main() {
    int n, i, p;
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> p;
        printf("%d", polindrom(p), "/n");
    }
}
