#include <iostream>
#include <random>

int rand_placing(int N, int coord[])
{
    int i, coord[N];
    for(i = 0; i < N; i++) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<int> dist(-10, 10);
        coord[i] = dist(rng);
    }
}

int rand_mooving()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, 4);
    return dist(rng);
}

void boundaries_checking(int x_coord[], int y_coord[], int conditions[], int &alive_particles, int N)
{
    int i = 0;
    for (i = 0; i < N; i++) {
        if (abs(x_coord[i]) != 10 || abs(y_coord[i]) != 10)
            conditions[i] = 1;
        else {
            conditions[i] = 0;
            alive_particles--;
        }
    }
}

void neighbour_checking(int x_coord[], int y_coord[], int conditions[], int &alive_particles, int N)
{
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            if(x_coord[i] == x_coord[j] && y_coord[i] == y_coord[j]){
                conditions[i] = 0;
                conditions[j] = 0;
            }
        }
}

void particle_moving(int x_coord[], int y_coord[], int conditions[], int N, int &alive_particles)
{
    int i, j, x_moves[N] = {0}, y_moves[N] = {0}, move = 0;
    for(i = 0; i < N; i++){
        if(conditions[i] == 1) {
            move = rand_mooving();
            if (move == 1)
                y_moves[i] = 1;
            else if (move == 2)
                x_moves[i] = 1;
            else if (move == 3)
                y_moves[i] = -1;
            else
                x_moves[i] = -1;
        }
    }
    for(i = 0; i < N; i++){
        if(conditions[i] == 1){
            x_coord[i] = x_coord[i] + x_moves[i];
            y_coord[i] = y_coord[i] + y_moves[i];
            for (j = i; j < N; j++) {
                if (x_coord[i] == x_coord[j] + x_moves[j] && y_coord[i] == y_coord[j] + y_moved[j]) {
                    conditions[i] = 0;
                    conditions[j] = 0;

                }
            }
        }
    }
}

int time_freezing(int N)
{
    int size = 21, time_fr = 0, alive_particles = N, i, j;
    int x_coord[N], y_coord[N], conditions[N];
    for(i = 0; i < N; i++)
        conditions[i] = 1;
    rand_placing(N, x_coord[]);
    rand_placing(N, y_coord[]);
    }
    while(alive_particles > 0) {
        particle_moving(x_coord[], y_coord[], conditions[], N, alive_particles);
        boundaries_checking(x_coord[], y_coord[], conditions[], alive_particles, N);
        neighbour_checking(x_coord[], y_coord[], conditions[], alive_particles, N);
        time_fr++;
    }
    return time_fr;
}

double average_time_freezing(int N)
{
    int i;
    double time = 0;
    for(i = 0; i < 10; i++){
        time = time + time_freezing(N);
    }
    return time / 10;
}

int main() {
    int N = 1;
    for(N = 1; N < 51; N += 1) {
        std::cout << N << ";       " << average_time_freezing(N) << "\n";
    }
    return 0;
}