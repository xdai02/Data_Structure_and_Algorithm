#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
#define INFINITY 65535

typedef int Vertex;

/**
 * �ڽӾ���ʵ��ͼ
 */
typedef struct Graph {
    char vertex[MAX];   //���涥����Ϣ
    int numV;           //��������
    int numE;           //������
    int weight[MAX][MAX];   //�ߵ�Ȩֵ
    bool isVisited[MAX];    //���ʱ�־
} Graph;

/**
 * ���ͼ������ȨֵΪ������
 * @param g - ͼ
 * @return - ��պ��ͼ
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
 * ����ͼ
 * @return - �������ͼ
 */
Graph* createGraph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if(!g) {
        return NULL;
    }

    printf("����ͼ�Ķ���������");
    scanf("%d", &g->numV);
    printf("����ͼ�ı�������");
    scanf("%d", &g->numE);

    clearGraph(g);      //���ͼ

    printf("\n");
    printf("*** ����ͼ�и��������Ϣ ***\n");
    for(int i = 0; i < g->numV; i++) {
        fflush(stdin);
        printf("��%d�����㱣������ݣ�", i+1);
        scanf("%c", &(g->vertex[i]));
    }

    char v1, v2;        //����
    int weight;         //Ȩֵ
    int i, j;
    printf("\n");
    printf("*** ���빹�ɱߵĶ��㼰��Ȩֵ ***\n");
    for(int k = 0; k < g->numE; k++) {
        fflush(stdin);
        printf("��%d������Ϣ������ ���� Ȩֵ����", k+1);
        scanf("%c %c %d", &v1, &v2, &weight);

        //�����ж����в��Ҷ���
        for(i = 0; v1 != g->vertex[i]; i++);
        for(j = 0; v2 != g->vertex[j]; j++);
        g->weight[i][j] = weight;
        g->weight[j][i] = weight;       //����ͼ�ڶԽǱ���Ȩֵ
    }

    return g;
}

void printGraph(Graph *g) {
    //�������������Ϣ
    for(int i = 0; i < g->numV; i++) {
        printf("\t%c", g->vertex[i]);
    }
    printf("\n");

    for(int i = 0; i < g->numV; i++) {
        printf("%c", g->vertex[i]);

        for(int j = 0; j < g->numV; j++) {
            printf("\t");
            if(g->weight[i][j] == INFINITY) {
                printf("Z");        //Z��ʾ�����
            } else {
                printf("%d", g->weight[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * ��շ��ʱ�־
 * @param g - ͼ
 */
void clearVisit(Graph *g) {
    for(int i = 0; i < g->numV; i++) {
        g->isVisited[i] = false;
    }
}

/**
 * ������ȱ���
 * @param g - ͼ
 * @param v - ��ʼ�����Ķ���
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

    printf("������ȱ���\n");
    clearVisit(g);
    dfs(g, 0);
    printf("\n");

    return 0;
}
