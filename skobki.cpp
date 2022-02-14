#include <iostream>

int main() {
    int n, i, left = 0, right = 0;
    char skob;
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> skob;
        if (skob == '(') left++;
        else right++;
        if (left < right) {
            printf("%d", -1);
            break;
        }
    }
    if (left == right) printf("%d", 1);
}
