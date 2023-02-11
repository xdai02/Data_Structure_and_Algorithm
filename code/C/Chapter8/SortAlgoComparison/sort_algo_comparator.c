#include "sort_algo_comparator.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif
#include <time.h>

typedef struct sort_algo_comparator {
    int *data;
    size_t size;
} sort_algo_comparator;

sort_algo_comparator *sort_algo_comparator_create() {
    sort_algo_comparator *comparator = (sort_algo_comparator *)malloc(sizeof(sort_algo_comparator));
    comparator->data = NULL;
    comparator->size = 0;
    return comparator;
}

void sort_algo_comparator_destroy(sort_algo_comparator *comparator) {
    if (comparator->data) {
        free(comparator->data);
    }
    free(comparator);
}

int sort_algo_comparator_read_data(sort_algo_comparator *comparator, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    int count = 0;
    int elem;
    while (fscanf(file, "%d", &elem) != EOF) {
        count++;
    }

    comparator->data = (int *)malloc(count * sizeof(int));
    if (!comparator->data) {
        fclose(file);
        return 0;
    }
    comparator->size = count;

    rewind(file);

    int *data = comparator->data;
    while (fscanf(file, "%d", data) != EOF) {
        data++;
    }

    fclose(file);
    return count;
}

void sort_algo_comparator_sort(sort_algo_comparator *comparator, void *(*sort)(void *args), const char *algo_name, int timeout) {
    // make a copy of data
    int *data = (int *)malloc(comparator->size * sizeof(int));
    memcpy(data, comparator->data, comparator->size * sizeof(int));

#ifdef _WIN32
    HANDLE tid;

    argument_t args = {data, comparator->size};
    tid = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)sort, &args, 0, NULL);

    printf("%s started...\n", algo_name);

    clock_t start_time = clock();

    DWORD result = WaitForSingleObject(tid, timeout * 1000);
    if (result == WAIT_TIMEOUT) {
        printf("%s timed out\n", algo_name);
        TerminateThread(tid, 0);
    } else {
        clock_t end_time = clock();
        printf("%s: %.3f seconds\n", algo_name, (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }

    CloseHandle(tid);
#else
    pthread_t tid;

    argument_t args = {data, comparator->size};
    pthread_create(&tid, NULL, sort, (void *)&args);

    printf("%s started...\n", algo_name);

    clock_t start_time = clock();

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += timeout;

    int result = pthread_timedjoin_np(tid, NULL, &ts);
    if (result == ETIMEDOUT) {
        printf("%s timed out\n", algo_name);
        pthread_cancel(tid);
    } else {
        clock_t end_time = clock();
        printf("%s: %.3f seconds\n", algo_name, (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }
#endif

    free(data);
}