#include <iostream>

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void select_sort (int array[], int n) {
    int max_id = 0;
    for (int i = 0; i < n - 1; ++i){
         max_id = 0;
         for (int j = 0; j < n - i; ++j){
             if (array[j] > array[max_id])
                 max_id = j;
         }
         swap(array[max_id], array[n - i - 1]);
    }
}
void print_array(int array[], int n){
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << ' ';
}

int main() {
    int array[] = {2, 5, 3, 8, 1, 10, 20, -1}, n = 8;
    select_sort(array, n);
    print_array(array, n);
}


