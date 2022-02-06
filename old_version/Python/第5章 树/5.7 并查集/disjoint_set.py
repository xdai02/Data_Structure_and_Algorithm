class DisjointSet:
    def __init__(self, n):
        """
            初始化每个元素的父结点
            初始时所有结点的父结点为自己本身
            Args:
                n (int): 元素数量
        """
        self.parent = []        # 父结点列表
        self.rank = []          # 秩
        for i in range(n):
            self.parent.append(i)
            self.rank.append(1)
        
    def find(self, val):
        """
            查询一个元素所在集合的根结点
            Args:
                val (int): 待查询元素
            Returns:
                [int]: 该集合根结点
        """
        if self.parent[val] == val:
            return val
        else:
            self.parent[val] = self.find(self.parent[val])
            return self.parent[val]

    def merge(self, i, j):
        """
            合并两个集合
            Args:
                i (int): 待合并元素1
                j (int): 待合并元素2
        """
        # 找到对应根结点
        x = self.find(i)
        y = self.find(j)
        if self.rank[x] <= self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
        # 如果深度相同且根结点不同，则新的根结点深度+1
        if self.rank[x] == self.rank[y] and x != y:
            self.rank[y] += 1

def main():
    disjoint_set = DisjointSet(7)

    disjoint_set.merge(3, 1)
    disjoint_set.merge(2, 1)
    disjoint_set.merge(5, 4)
    disjoint_set.merge(6, 4)
    disjoint_set.merge(4, 1)

    print(disjoint_set.find(6))

if __name__ == "__main__":
    main()