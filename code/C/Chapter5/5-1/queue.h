#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct queue_t queue_t;

queue_t *queue_create();
void queue_destroy(queue_t *queue);
int queue_size(queue_t *queue);
bool queue_is_empty(queue_t *queue);
queue_t *queue_enqueue(queue_t *queue, T elem);
T queue_dequeue(queue_t *queue);
T queue_front(queue_t *queue);

#endif