#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Queue {
    dataType *data;     // 数据域
    int front;          // 队头
    int rear;           // 队尾
    int max;            // 队列容量
} Queue;

/**
 * @brief  初始化队列
 * @note   循环队列需要保留一个空位
 * @param  size: 队列容量
 * @retval 队列指针
 */
Queue* init(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if(!queue) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    queue->data = (dataType *)malloc((size+1) * sizeof(dataType));
    if(!queue->data) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    queue->front = queue->rear = 0;
    queue->max = size + 1;
    return queue;
}

/**
 * @brief  判断队列是否为空
 * @param  queue: 队列指针
 * @retval 空队列返回true，非空返回false
 */
bool isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

/**
 * @brief  判断队列是否已满
 * @param  queue: 队列指针
 * @retval 满队列返回true，未满返回false
 */
bool isFull(Queue *queue) {
    return (queue->rear + 1) % queue->max == queue->front;
}

/**
 * @brief  入队
 * @param  queue: 队列指针
 * @param  val: 入队元素
 * @retval 入队成功返回true，失败返回false
 */
void enqueue(Queue *queue, dataType val) {
    if(isFull(queue)) {
        fprintf(stderr, "Error: queue is full.\n");
        return false;
    }
    queue->data[queue->rear] = val;
    queue->rear = (queue->rear + 1) % (queue->max);
}

/**
 * @brief  出队
 * @note   可能引发空队列异常
 * @param  queue: 队列指针
 * @retval 出队元素
 */
dataType dequeue(Queue *queue) {
    if(isEmpty(queue)) {
        fprintf(stderr, "Error: queue is empty.\n");
        exit(1);
    }
    dataType ret = queue->data[queue->front];
    queue->front = (queue->front + 1) % (queue->max);
    return ret;
}

/**
 * @brief  销毁队列
 * @param  queue: 队列指针
 */
void destroyQueue(Queue *queue) {
    if(!queue) {
        return;
    }
    free(queue->data);
    free(queue);
    queue->data = NULL;
    queue = NULL;
}

int main() {
    Queue *q = init(5);

    enqueue(q, 1);              // 头 [1] 尾
    enqueue(q, 2);              // 头 [1, 2] 尾
    enqueue(q, 3);              // 头 [1, 2, 3] 尾
    enqueue(q, 4);              // 头 [1, 2, 3, 4] 尾
    enqueue(q, 5);              // 头 [1, 2, 3, 4, 5] 尾

    while(!isEmpty(q)) {
        printf("%d\n", dequeue(q));
    }

    destroyQueue(q);
    return 0;
}
