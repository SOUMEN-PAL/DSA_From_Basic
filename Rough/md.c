#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define bus_c 3
#define num_psg 10

sem_t mutex, bus_arrived, passenger_boarded;
int waiting_count = 0;
int psg_boarded = 0;
int all_psg_boarded = 0;

void board() {
    printf("Passenger boarded\n");
}

void depart() {
    printf("Bus departed with %d passengers\n", bus_c);

}

void* passengers_thread(void* arg) {
    while (1) {
        sem_wait(&mutex);
        if (psg_boarded >= num_psg) {
            sem_post(&mutex);
            break;
        }
        waiting_count++;
        sem_post(&mutex);

        sem_wait(&bus_arrived);
        board();
        sem_post(&passenger_boarded);

        sem_wait(&mutex);
        psg_boarded++;
        if (psg_boarded >= num_psg) {
            all_psg_boarded = 1;
        }
        sem_post(&mutex);
    }
    return NULL;
}
void* bus_thread(void* arg) {
    while (!all_psg_boarded) {
        sem_wait(&mutex);
        if (waiting_count >= bus_c) {
            for (int i = 0; i < bus_c; i++) {
                sem_post(&bus_arrived);
                sem_wait(&passenger_boarded);
                waiting_count--;
            }
            depart();
        }
        sem_post(&mutex);
    }
    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&bus_arrived, 0, 0);
    sem_init(&passenger_boarded, 0, 0);

    pthread_t bus, passengers[num_psg];
    pthread_create(&bus, NULL, bus_thread, NULL);
    for (int i = 0; i < num_psg; i++) {
        pthread_create(&passengers[i], NULL, passengers_thread, NULL);
    }
    pthread_join(bus, NULL);
    for (int i = 0;i < num_psg;i++) {
        pthread_join(passengers[i], NULL);
    }
    return 0;
}