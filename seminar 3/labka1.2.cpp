#include <iostream>
#include <random>

void rand_placing(int N, int coord[])
{
    int i;
    for(i = 0; i < N; i++) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<int> dist(-6, 6);
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

void boundaries_checking(int x_coord[], int y_coord[], int conditions[], int N)
{
    int i = 0;
    for (i = 0; i < N; i++) {
        if (abs(x_coord[i]) < 6 && abs(y_coord[i]) < 6)
            conditions[i] = 1;
        else {
            conditions[i] = 0;
        }
    }
}

void neighbour_checking(int x_coord[], int y_coord[], int conditions[], int N)
{
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            if(abs(x_coord[i] - x_coord[j]) == 1 && y_coord[i] == y_coord[j]){
                conditions[i] = 0;
                conditions[j] = 0;
            }
            else if(abs(y_coord[i] - y_coord[j]) == 1 && x_coord[i] == x_coord[j]){
                conditions[i] = 0;
                conditions[j] = 0;
            }
        }
}

void particle_moving(int x_coord[], int y_coord[], int conditions[], int N)
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
                if(x_coord[i] == x_coord[j] + x_moves[j] && y_coord[i] == y_coord[j] + y_moves[j]) {
                    conditions[i] = 0;
                    conditions[j] = 0;
                }
            }
        }
    }
}

int time_freezing(int N)
{
    int time_fr = 0, alive_particles = N, i = 0, s = 0;
    int x_coord[N], y_coord[N], conditions[N];
    for(i = 0; i < N; i++)
        conditions[i] = 1;
    rand_placing(N, x_coord);
    rand_placing(N, y_coord);
    boundaries_checking(x_coord, y_coord, conditions, N);
    neighbour_checking(x_coord, y_coord, conditions, N);
    alive_particles = 0;
    for(i = 0; i < N; i++)
        alive_particles = alive_particles + conditions[i];
    while(alive_particles > 0) {
        particle_moving(x_coord, y_coord, conditions, N);
        boundaries_checking(x_coord, y_coord, conditions, N);
        neighbour_checking(x_coord, y_coord, conditions, N);
        time_fr++;
        alive_particles = 0;
        for(i = 0; i < N; i++)
            alive_particles = alive_particles + conditions[i];
    }
    return time_fr;
}

double average_time_freezing(int N){
    int i;
    double time = 0;
    for(i = 0; i < 100; i++)
        time = time + time_freezing(N);
    return time / 500;
}

int main(){
    int N;
    for(N = 1; N < 90; N++) {
        std::cout << N << ";       " << average_time_freezing(N) << "\n";
    }
}