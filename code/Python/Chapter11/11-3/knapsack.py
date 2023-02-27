class Item:
    def __init__(self, type, weight, value):
        """
            初始化物品
            Args:
                type (int): 物品类型
                weight (float): 重量
                value (float): 价值
        """
        self.type = type
        self.weight = weight
        self.value = value
        self.unit_value = value / weight    # 单位价值

def main():
    # capacity = 30       # 背包容量
    # item_type = [1, 2, 3, 4, 5]
    # item_weight = [10, 5, 15, 10, 30]
    # item_value = [20, 30, 15, 25, 10]
    capacity = 8       # 背包容量
    item_type = [1, 2, 3, 4]
    item_weight = [2,3,4,5]
    item_value = [3,4,5,6]

    items = []
    for i in range(len(item_type)):
        items.append(
            Item(item_type[i], item_weight[i], item_value[i])
        )
    
    # 物品按照单价降序排列
    items.sort(key=lambda x: x.unit_value, reverse=True)

    # 背包选择
    selected_items = []
    cur_weight = 0          # 当前背包重量
    for item in items:
        if cur_weight + item.weight <= capacity:
            cur_weight += item.weight
            selected_items.append(item)
        else:
            item.weight = capacity - cur_weight
            selected_items.append(item)
            break
    
    # 输出选择结果
    for item in selected_items:
        print("物品%d，重量：%.2f" % (item.type, item.weight))

if __name__ == "__main__":
    main()