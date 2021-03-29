#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Queue {
    dataType *data;     // ������
    int front;          // ��ͷ
    int rear;           // ��β
    int max;            // ��������
} Queue;

/**
 * @brief  ��ʼ������
 * @note   ѭ��������Ҫ����һ����λ
 * @param  size: ��������
 * @retval ����ָ��
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
 * @brief  �ж϶����Ƿ�Ϊ��
 * @param  queue: ����ָ��
 * @retval �ն��з���true���ǿշ���false
 */
bool isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

/**
 * @brief  �ж϶����Ƿ�����
 * @param  queue: ����ָ��
 * @retval �����з���true��δ������false
 */
bool isFull(Queue *queue) {
    return (queue->rear + 1) % queue->max == queue->front;
}

/**
 * @brief  ���
 * @param  queue: ����ָ��
 * @param  val: ���Ԫ��
 * @retval ��ӳɹ�����true��ʧ�ܷ���false
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
 * @brief  ����
 * @note   ���������ն����쳣
 * @param  queue: ����ָ��
 * @retval ����Ԫ��
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
 * @brief  ���ٶ���
 * @param  queue: ����ָ��
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

    enqueue(q, 1);              // ͷ [1] β
    enqueue(q, 2);              // ͷ [1, 2] β
    enqueue(q, 3);              // ͷ [1, 2, 3] β
    enqueue(q, 4);              // ͷ [1, 2, 3, 4] β
    enqueue(q, 5);              // ͷ [1, 2, 3, 4, 5] β

    while(!isEmpty(q)) {
        printf("%d\n", dequeue(q));
    }

    destroyQueue(q);
    return 0;
}
