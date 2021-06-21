#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX         10          // 最大顶点数量
#define INFINITY    65535       // 无穷大

#define UNDIRECTED  0           // 无向图
#define DIRECTED    1           // 有向图

typedef char Vertex;            // 顶点
typedef int Edge;               // 边

// 图
typedef struct Graph {
    int type;                   // 图的类型（无向图-0 / 有向图-1）
    Vertex vertex[MAX];         // 顶点名称
    int vertexNum;              // 顶点数量
    int edgeNum;                // 边数量
    int weight[MAX][MAX];       // 邻接矩阵
} Graph;

bool isVisited[MAX];            // 访问标志

/**
 * @brief  创建图
 * @note   指定格式输入图的信息（txt文件提供样例）
 * @retval 图结构指针
 */
Graph* createGraph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if(!g) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(i == j) {
                g->weight[i][j] = 0;
            } else {
                g->weight[i][j] = INFINITY;
            }
        }
    }

    printf("图的类型（无向图-0 / 有向图-1）：");
    scanf("%d", &g->type);

    printf("图的顶点数量：");
    scanf("%d", &g->vertexNum);
    for(int i = 0; i < g->vertexNum; i++) {
        fflush(stdin);          // 清空缓冲区
        printf("输入第%d个顶点名称：", i+1);
        scanf("%c", &g->vertex[i]);
    }

    printf("图的边数量：");
    scanf("%d", &g->edgeNum);
    for(int i = 0; i < g->edgeNum; i++) {
        char src, dst;          // 起始顶点 目标顶点
        int weight;             // 边的权值
        int v1, v2;             // 起始顶点下标 目标顶点下标

        fflush(stdin);          // 清空缓冲区
        printf("输入第%d条边信息（起始顶点 目标顶点 权值）：", i+1);
        scanf("%c %c %d", &src, &dst, &weight);

        // 在已有的顶点中查找顶点下标
        for(v1 = 0; src != g->vertex[v1]; v1++);
        for(v2 = 0; dst != g->vertex[v2]; v2++);
        g->weight[v1][v2] = weight;
        // 无向图在对角保存相同权值
        if(g->type == UNDIRECTED) {
            g->weight[v2][v1] = weight;
        }
    }

    return g;
}

/**
 * @brief  输出图的邻接矩阵
 * @param  g: 图结构指针
 */
void printGraph(Graph *g) {
    // 首行输出顶点名称
    for(int i = 0; i < g->vertexNum; i++) {
        printf("\t%2c", g->vertex[i]);
    }
    printf("\n");
    for(int i = 0; i < g->vertexNum * MAX; i++) {
        printf("-");
    }
    printf("\n");

    for(int i = 0; i < g->vertexNum; i++) {
        printf("%2c", g->vertex[i]);
        for(int j = 0; j < g->vertexNum; j++) {
            printf("\t");
            if(g->weight[i][j] == INFINITY) {
                printf("%4s", "∞");
            } else {
                printf("%2d", g->weight[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
}

/**
 * @brief  清空顶点的访问标志
 * @note   全局变量isVisited
 */
void clearFlag() {
    for(int i = 0; i < MAX; i++) {
        isVisited[i] = false;
    }
}

/**
 * @brief  深度优先遍历
 * @param  g: 图结构指针
 * @param  v: 开始遍历的顶点
 */
void dfs(Graph *g, Vertex vertex) {
    // 在已有的顶点中查找顶点下标
    int v;
    for(v = 0; vertex != g->vertex[v]; v++);

    // 访问当前顶点
    printf("-> %c ", g->vertex[v]);
    isVisited[v] = true;

    // 递归深度遍历当前顶点所有未访问过的邻接点
    for(int i = 0; i < g->vertexNum; i++) {
        if(g->weight[v][i] != INFINITY && !isVisited[i]) {
            dfs(g, g->vertex[i]);
        }
    }
}

/**
 * @brief  Floyd算法计算多源最短路径
 * @param  g: 图结构指针
 * @param  dist: 最短路径矩阵
 */
void floyd(Graph *g, int dist[MAX][MAX]) {
    // 最短路径矩阵初始化为图的邻接矩阵
    for(int i = 0; i < g->vertexNum; i++) {
        for(int j = 0; j < g->vertexNum; j++) {
            dist[i][j] = g->weight[i][j];
        }
    }

    // Floyd算法
    for(int k = 0; k < g->vertexNum; k++) {
        for(int i = 0; i < g->vertexNum; i++) {
            for(int j = 0; j < g->vertexNum; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

/**
 * @brief  打印最短路径矩阵
 * @param  g: 图结构指针
 * @param  dist: 最短路径矩阵
 */
void printShortestDistance(Graph *g, int dist[MAX][MAX]) {
    // 首行输出顶点名称
    for(int i = 0; i < g->vertexNum; i++) {
        printf("\t%2c", g->vertex[i]);
    }
    printf("\n");
    for(int i = 0; i < g->vertexNum * MAX; i++) {
        printf("-");
    }
    printf("\n");

    for(int i = 0; i < g->vertexNum; i++) {
        printf("%2c", g->vertex[i]);
        for(int j = 0; j < g->vertexNum; j++) {
            printf("\t");
            if(dist[i][j] == INFINITY) {
                printf("%4s", "∞");
            } else {
                printf("%2d", dist[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
}

int main() {
    Graph *g = createGraph();       // 创建图

    printGraph(g);                  // 打印邻接矩阵

    clearFlag();
    printf("深度优先遍历：");
    dfs(g, 'A');                    // 指定源点开始dfs
    printf("\n");

    // Floyd算法计算多源最短路径
    int dist[MAX][MAX];
    floyd(g, dist);
    printf("多源最短路径：\n");
    printShortestDistance(g, dist);

    free(g);
    return 0;
}