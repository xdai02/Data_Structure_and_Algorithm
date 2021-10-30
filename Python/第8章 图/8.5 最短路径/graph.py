MAX = 10            # 最大顶点数量
INFINITY = 65535    # 无穷大

class Graph:
    """
        图
    """
    UNDIRECTED = 0      # 无向图
    DIRECTED = 1        # 有向图

    def __init__(self):
        """
            创建图
            指定格式输入图的信息（txt文件提供样例）
        """
        self.is_visited = [False] * MAX    # 访问标志
        
        # 初始化邻接矩阵
        self.weight = [INFINITY] * MAX
        for i in range(MAX):
            self.weight[i] = [INFINITY] * MAX
            self.weight[i][i] = 0
        
        self.type = int(input("图的类型（无向图-0 / 有向图-1）："))

        self.vertex = []        # 顶点
        self.vertexNum = int(input("图的顶点数量："))
        for i in range(self.vertexNum):
            self.vertex.append(input("输入第%d个顶点名称：" % (i+1)))
        
        self.edgeNum = int(input("图的边数量："))
        for i in range(self.edgeNum):
            info = input("输入第%d条边信息（起始顶点 目标顶点 权值）：" % (i+1))
            src, dst, wgt = info.split(" ")
            wgt = int(wgt)

            # 在已有的顶点中查找顶点下标
            v1 = v2 = 0
            while src != self.vertex[v1]:
                v1 += 1
            while dst != self.vertex[v2]:
                v2 += 1
            self.weight[v1][v2] = wgt
            # 无向图在对角保存相同权值
            if self.type == self.UNDIRECTED:
                self.weight[v2][v1] = wgt
    
    def print_graph(self):
        """
            输出图的邻接矩阵
        """
        # 首行输出顶点名称
        for i in range(self.vertexNum):
            print("\t%2c" % self.vertex[i], end='')
        print()
        for _ in range(self.vertexNum * MAX):
            print("-", end='')
        print()

        for i in range(self.vertexNum):
            print("%2c" % self.vertex[i], end='')
            for j in range(self.vertexNum):
                print("\t", end='')
                if self.weight[i][j] == INFINITY:
                    print("%2s" % "∞", end='')
                else:
                    print("%2d" % self.weight[i][j], end='')
                print("|", end='')
            print()
    
    def clear_flag(self):
        """
            清空顶点的访问标志is_visited
        """
        self.is_visited = [False] * MAX

    def dfs(self, vertex):
        """
            深度优先遍历
            Args:
                vertex ([str]): 开始遍历的顶点
        """
        # 在已有的顶点中查找顶点下标
        v = 0
        while vertex != self.vertex[v]:
            v += 1
        
        # 访问当前顶点
        print("-> %c " % self.vertex[v], end='')
        self.is_visited[v] = True
        
        # 递归深度遍历当前顶点所有未访问过的邻接点
        for i in range(self.vertexNum):
            if self.weight[v][i] != INFINITY and not self.is_visited[i]:
                self.dfs(self.vertex[i])
    
    def floyd(self):
        """
            Floyd算法计算多源最短路径
            Returns:
                [[list]]: 最短路径矩阵
        """
        # 最短路径矩阵初始化为图的邻接矩阵
        dist = self.weight

        # Floyd算法
        for k in range(self.vertexNum):
            for i in range(self.vertexNum):
                for j in range(self.vertexNum):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        return dist
    
    def print_shortest_distance(self, dist):
        """
            打印最短路径矩阵
            Args:
                dist ([[list]]): 最短路径矩阵
        """
        # 首行输出顶点名称
        for i in range(self.vertexNum):
            print("\t%2c" % self.vertex[i], end='')
        print()
        for _ in range(self.vertexNum * MAX):
            print("-", end='')
        print()

        for i in range(self.vertexNum):
            print("%2c" % self.vertex[i], end='')
            for j in range(self.vertexNum):
                print("\t", end='')
                if dist[i][j] == INFINITY:
                    print("%2s" % "∞", end='')
                else:
                    print("%2d" % dist[i][j], end='')
                print("|", end='')
            print()

def main():
    graph = Graph()         # 创建图

    graph.print_graph()     # 打印邻接矩阵

    graph.clear_flag()
    print("深度优先遍历：", end='')
    graph.dfs('1')          # 指定源点开始dfs
    print()

    # Floyd算法计算多源最短路径
    dist = graph.floyd();
    print("多源最短路径：");
    graph.print_shortest_distance(dist)

if __name__ == "__main__":
    main()