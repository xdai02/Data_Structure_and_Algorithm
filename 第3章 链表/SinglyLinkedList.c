#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Node {
    dataType data;          // 数据域
    struct Node *next;      // 指针域
} Node, List;

/**
 * @brief  初始化链表
 * @retval 链表头指针
 */
List* init() {
    List *node = (List *)malloc(sizeof(List));
    if(!node) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    node->next = NULL;
    return node;
}

/**
 * @brief  判断是否是空链表
 * @param  head: 链表头指针
 * @retval 空链表返回true，为空链表返回false
 */
bool isEmpty(List *head) {
    return head->next == NULL;
}

/**
 * @brief  获取链表长度
 * @param  head: 链表头指针
 * @retval 链表长度
 */
int getLength(List *head) {
    List *temp = head;
    int len = 0;
    while(temp->next) {
        temp = temp->next;
        len++;
    }
    return len;
}

/**
 * @brief  打印链表
 * @param  head: 链表头指针
 */
void show(List *head) {
    List *temp = head;
    while(temp->next) {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

/**
 * @brief  插入结点
 * @param  head: 链表头指针
 * @param  pos: 插入位置
 * @param  val: 插入元素
 * @retval 链表头指针
 */
List* insert(List *head, int pos, dataType val) {
    // 超出链表范围
    if(pos < 0 || pos > getLength(head)) {
        fprintf(stderr, "Error: position out of bound.\n");
		return head;
	}

    // 创建新结点
	Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return head;
    }
    newNode->data = val;
    newNode->next = NULL;

    // 找到插入位置
    List *temp = head;
    for(int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

/**
 * @brief  删除结点
 * @param  head: 链表头指针
 * @param  pos: 插入位置
 * @retval 链表头指针
 */
List* delete(List *head, int pos) {
    // 超出链表范围
    if(pos < 0 || pos >= getLength(head)) {
        fprintf(stderr, "Error: position out of bound.\n");
		return head;
	}
    
    // 找到删除位置
    List *temp = head;
    for(int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    del = NULL;
    return head;
}

/**
 * @brief  查找元素
 * @param  head: 链表头指针
 * @param  val: 查找值
 * @retval 返回结点指针，未找到返回NULL
 */
Node* search(List *head, dataType val) {
    // 查找元素位置
    List *temp = head;
    while(temp->next) {
        temp = temp->next;
        if(temp->data == val) {
            return temp;
        }
    }
    return NULL;        // 未找到
}

/**
 * @brief  修改元素
 * @param  head: 链表头指针
 * @param  pos: 修改位置
 * @param  val - 新数据
 * @retval 链表头指针
 */
List* set(List *head, int pos, dataType val) {
    // 超出链表范围
    if(pos < 0 || pos >= getLength(head)) {
        fprintf(stderr, "Error: position out of bound.\n");
		return head;
	}

    // 找到元素位置
	List *temp = head->next;
    for(int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    temp->data = val;
    return head;
}

/**
 * @brief  销毁链表
 * @param  head: 链表头指针
 */
void destroyList(List *head) {
    if(!head) {
        return;
    }
    while(!isEmpty(head)) {
        delete(head, 0);
    }
    free(head);
    head = NULL;
}

int main() {
    List *list = init();

    insert(list, 0, 1);         // [1]
    insert(list, 0, 2);         // [2, 1]
    insert(list, 2, 3);         // [2, 1, 3]
    show(list);

    delete(list, 0);            // [1, 3]
    insert(list, 1, 4);         // [1, 4, 3]
    delete(list, 2);            // [1, 4]
    show(list);

    set(list, 0, 5);            // [5, 4]
    set(list, 1, 6);            // [5, 6]
    show(list);

    printf("%d\n", search(list, 6)->data);  // 6
    destroyList(list);

    return 0;
}