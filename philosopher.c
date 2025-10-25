// File: dining_philosophers.c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num;
    while (1) {
        printf("Philosopher %d is thinking\n", id);
        sleep(1);
        pthread_mutex_lock(&chopstick[id]);
        pthread_mutex_lock(&chopstick[(id+1)%N]);
        printf("Philosopher %d is eating\n", id);
        sleep(1);
        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id+1)%N]);
    }
}

int main() {
    pthread_t ph[N];
    int ids[N];
    for (int i=0;i<N;i++) pthread_mutex_init(&chopstick[i], NULL);
    for (int i=0;i<N;i++) { ids[i]=i; pthread_create(&ph[i], NULL, philosopher, &ids[i]); }
    for (int i=0;i<N;i++) pthread_join(ph[i], NULL);
}
