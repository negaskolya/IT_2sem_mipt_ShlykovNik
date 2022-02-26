#include <iostream>

int indexfind(int array[], int num, int minimum, int maximum)
{
    int mid = (minimum + maximum) / 2;
    if (num < array[mid])
        return indexfind(array, num, minimum, mid);
    else if (array[mid] == num)
        return mid;
    else if (maximum - minimum == 1)
        return -1;
    else
        return indexfind(array, num, mid, maximum);
}

int main() {
    int number, size, array1[0], a = 0, i = 0;
    std::cin >> size;
    int array[size];
    for(i = 0; i < size; i++) {
        array[i] = i;
    }
    std::cin >> number;
    int index = indexfind(array, number, 0, size - 1);
    if (index < 0)
        std::cout << "No such number in array";
    else
        printf("%d", index);
}
