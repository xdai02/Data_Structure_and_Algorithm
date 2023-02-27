#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int type;			// 物品类型
    double weight;		// 重量
    double value;		// 价值
    double unitValue;	// 单位价值
} Item;

Item createItem(int type, double weight, double value) {
    Item item;
    item.type = type;
    item.weight = weight;
    item.value = value;
    item.unitValue = value / weight;
    return item;
}

int cmp(const void *_a, const void *_b) {
    Item *a = (Item *)_a;
    Item *b = (Item *)_b;
    return b->unitValue - a->unitValue;
}

int main() {
    double capacity = 30;		// 背包容量
    int itemType[] = {1, 2, 3, 4, 5};
    double itemWeight[] = {10, 5, 15, 10, 30};
    double itemValue[] = {20, 30, 15, 25, 10};
    int n = sizeof(itemType) / sizeof(itemType[0]);

    Item *items = (Item *)malloc(sizeof(Item) * n);
    if(!items) {
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        items[i] = createItem(itemType[i], itemWeight[i], itemValue[i]);
    }

    // 物品按照单价降序排列
    qsort(items, n-1, sizeof(Item), cmp);
    for(int i = 0; i < n; i++) {
        printf("%.2f\n", items[i].unitValue);
    }

    // 背包选择
    Item *selectItems = (Item *)malloc(sizeof(Item) * n);
    int cnt = 0;
    if(!selectItems) {
        exit(1);
    }
    double curWeight = 0;		// 当前背包重量
    for(int i = 0; i < n; i++) {
        if(curWeight + items[i].weight <= capacity) {
            curWeight += items[i].weight;
            selectItems[cnt++] = items[i];
        } else {
            items[i].weight = capacity - curWeight;
            selectItems[cnt++] = items[i];
            break;
        }
    }

    // 输出选择结果
    for(int i = 0; i < cnt; i++) {
        printf("物品%d，重量：%.2f\n", selectItems[i].type, selectItems[i].weight);
    }

    free(items);
    free(selectItems);
    return 0;
}