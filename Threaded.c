// File: prime_threads.c
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define LIMIT 100000
#define THREADS 4
int primes[LIMIT+1];

void* sieve(void* arg) {
    int tid = *(int*)arg;
    for (int n = 2+tid; n <= LIMIT; n += THREADS) {
        int prime = 1;
        for (int i=2;i<=sqrt(n);i++) if (n%i==0) { prime=0; break; }
        primes[n] = prime;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t[THREADS];
    int ids[THREADS];
    for (int i=0;i<THREADS;i++) { ids[i]=i; pthread_create(&t[i], NULL, sieve, &ids[i]); }
    for (int i=0;i<THREADS;i++) pthread_join(t[i], NULL);
    printf("Primes:\n");
    for (int i=2;i<=100;i++) if (primes[i]) printf("%d ", i);
}
