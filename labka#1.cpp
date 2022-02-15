#include <iostream>
#include <random>

double average_time_counter(int size)
{
    int i = 0;
    double time = 0;
    for(i = 0; i < 500; i++) {
        int x = 0, y = 0;
        while(true) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<int> dist(1, 4);
            int move = dist(rng);
            if (move == 1) y++;
            else if (move == 2) x++;
            else if (move == 3) y--;
            else x--;
            if (abs(x) >= size / 2 || abs(y) >= size / 2) {
                time++;
                break;
            }
            else
                time ++;
        }
    }
    double average_time = time / 500;
    return average_time;
}

int main() {
    std::cout << "Size  average_time\n";
    int s = 1;
    for(s = 1; s < 21; s += 2) {
        std::cout << s << ";       " << average_time_counter(s) << "\n";
    }
    return 0;
}