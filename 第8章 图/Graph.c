#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
#define INFINITY 65535

typedef int Vertex;

/**
 * 邻接矩阵实现图
 */
typedef struct Graph {
    char vertex[MAX];   //保存顶点信息
    int numV;           //顶点数量
    int numE;           //边数量
    int weight[MAX][MAX];   //边的权值
    bool isVisited[MAX];    //访问标志
} Graph;

/**
 * 清空图，设置权值为正无穷
 * @param g - 图
 * @return - 清空后的图
 */
Graph* clearGraph(Graph *g) {
    for(int i = 0; i < g->numV; i++) {
        for(int j = 0; j < g->numV; j++) {
            g->weight[i][j] = INFINITY;
        }
    }
    return g;
}

/**
 * 创建图
 * @return - 创建后的图
 */
Graph* createGraph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if(!g) {
        return NULL;
    }

    printf("输入图的顶点数量：");
    scanf("%d", &g->numV);
    printf("输入图的边数量：");
    scanf("%d", &g->numE);

    clearGraph(g);      //清空图

    printf("\n");
    printf("*** 输入图中各顶点的信息 ***\n");
    for(int i = 0; i < g->numV; i++) {
        fflush(stdin);
        printf("第%d个顶点保存的数据：", i+1);
        scanf("%c", &(g->vertex[i]));
    }

    char v1, v2;        //顶点
    int weight;         //权值
    int i, j;
    printf("\n");
    printf("*** 输入构成边的顶点及其权值 ***\n");
    for(int k = 0; k < g->numE; k++) {
        fflush(stdin);
        printf("第%d条边信息（顶点 顶点 权值）：", k+1);
        scanf("%c %c %d", &v1, &v2, &weight);

        //在已有顶点中查找顶点
        for(i = 0; v1 != g->vertex[i]; i++);
        for(j = 0; v2 != g->vertex[j]; j++);
        g->weight[i][j] = weight;
        g->weight[j][i] = weight;       //无向图在对角保存权值
    }

    return g;
}

void printGraph(Graph *g) {
    //首行输出顶点信息
    for(int i = 0; i < g->numV; i++) {
        printf("\t%c", g->vertex[i]);
    }
    printf("\n");

    for(int i = 0; i < g->numV; i++) {
        printf("%c", g->vertex[i]);

        for(int j = 0; j < g->numV; j++) {
            printf("\t");
            if(g->weight[i][j] == INFINITY) {
                printf("Z");        //Z表示无穷大
            } else {
                printf("%d", g->weight[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * 清空访问标志
 * @param g - 图
 */
void clearVisit(Graph *g) {
    for(int i = 0; i < g->numV; i++) {
        g->isVisited[i] = false;
    }
}

/**
 * 深度优先遍历
 * @param g - 图
 * @param v - 开始遍历的顶点
 */
void dfs(Graph *g, Vertex v) {
    printf("%c\t", g->vertex[v]);
    g->isVisited[v] = true;

    for(int i = 0; i < g->numV; i++) {
        if(g->weight[v][i] != INFINITY) {
            if(!g->isVisited[i]) {
                dfs(g, i);
            }
        }
    }
}

int main() {
    Graph *g = createGraph();

    printGraph(g);

    printf("深度优先遍历\n");
    clearVisit(g);
    dfs(g, 0);
    printf("\n");

    return 0;
}
