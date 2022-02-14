#include <iostream>

char stroka (int b, int c)
{
    int j;
    for(j = 0; j < 2 * b - 1; j++){
        if (j < c) {
            std::cout << char('A' + j);
        }
        else if (j >= 2 * b - 1 - c) {
            std::cout << char('A' + 2 * b - 2 - j);
        }
        else std::cout << ' ';
    }
    std::cout << '\n';
}

void piramid(int a)
{
    int i;
    for(i = 0; i < a; i++) {
        stroka(a, a - i);
    }
}

int main() {
    int n;
    std::cin >> n;
    piramid(n);
}
