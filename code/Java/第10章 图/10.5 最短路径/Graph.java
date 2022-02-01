import java.util.Scanner;

public class Graph {
	private final static int MAX = 10;			// ��󶥵���
	private final static int INFINITY = 65535;	// �����
	
	private final static int UNDIRECTED = 0;	// ����ͼ
	private final static int DIRECTED = 1;		// ����ͼ
	
	private int type;				// ͼ�����ͣ�����ͼ-0 / ����ͼ-1��
	private char[] vertex;			// ��������
	private int vertexNum;			// ��������
	private int edgeNum;			// ������
	private int[][] weight;			// �ڽӾ���
	
	private boolean[] isVisited;	// ���ʱ�־
	
	/**
	 * @brief  ����ͼ
	 * ָ����ʽ����ͼ����Ϣ��txt�ļ��ṩ������
	 */
	public Graph() {
		vertex = new char[MAX];
		weight = new int[MAX][MAX];
		isVisited = new boolean[MAX];
		
		for(int i = 0; i < MAX; i++) {
			for(int j = 0; j < MAX; j++) {
				if(i == j) {
					this.weight[i][j] = 0;
				} else {
					this.weight[i][j] = INFINITY;
				}
			}
		}
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("ͼ�����ͣ�����ͼ-0 / ����ͼ-1����");
		this.type = scanner.nextInt();
		
		System.out.print("ͼ�Ķ���������");
		this.vertexNum = scanner.nextInt();
		for(int i = 0; i < this.vertexNum; i++) {
			System.out.print("�����" + (i+1) + "���������ƣ�");
			this.vertex[i] = scanner.next().charAt(0);
		}
		
		System.out.print("ͼ�ı�������");
		this.edgeNum = scanner.nextInt();
		for(int i = 0; i < this.edgeNum; i++) {
			char src, dst;          // ��ʼ���� Ŀ�궥��
	        int weight;             // �ߵ�Ȩֵ
	        int v1, v2;             // ��ʼ�����±� Ŀ�궥���±�
	        
			System.out.print("�����" + (i+1) + "������Ϣ����ʼ���� Ŀ�궥�� Ȩֵ����");
	        src = scanner.next().charAt(0);
	        dst = scanner.next().charAt(0);
	        weight = scanner.nextInt();
	        
	        // �����еĶ����в��Ҷ����±�
	        for(v1 = 0; src != this.vertex[v1]; v1++);
	        for(v2 = 0; dst != this.vertex[v2]; v2++);
	        this.weight[v1][v2] = weight;
        	// ����ͼ�ڶԽǱ�����ͬȨֵ
	        if(this.type == UNDIRECTED) {
	        	this.weight[v2][v1] = weight;
	        }
		}	
		scanner.close();
	}
	
	/**
	 * @brief  ���ͼ���ڽӾ���
	 */
	public void printGraph() {
		// ���������������
	    for(int i = 0; i < this.vertexNum; i++) {
	    	System.out.print(String.format("\t%2c", this.vertex[i]));
	    }
	    System.out.println();
	    for(int i = 0; i < this.vertexNum * MAX; i++) {
	    	System.out.print("-");
	    }
	    System.out.println();
	    
	    for(int i = 0; i < this.vertexNum; i++) {
	    	System.out.print(String.format("%2c", this.vertex[i]));
	    	for(int j = 0; j < this.vertexNum; j++) {
	    		System.out.print("\t");
	    		if(this.weight[i][j] == INFINITY) {
	    			System.out.print(String.format("%2s", "��"));
	    		} else {
	    			System.out.print(String.format("%2d", this.weight[i][j]));
	    		}
	    		System.out.print("|");
	    	}
	    	System.out.println();
	    }
	}
	
	/**
	 * @brief  ��ն���ķ��ʱ�־isVisited
	 */
	public void clearFlag() {
	    for(int i = 0; i < MAX; i++) {
	        this.isVisited[i] = false;
	    }
	}
	
	/**
	 * @brief  ������ȱ���
	 * @param  v: ��ʼ�����Ķ���
	 */
	public void dfs(char vertex) {
	    // �����еĶ����в��Ҷ����±�
	    int v;
	    for(v = 0; vertex != this.vertex[v]; v++);

	    // ���ʵ�ǰ����
	    System.out.print("-> " + this.vertex[v] + " ");
	    this.isVisited[v] = true;

	    // �ݹ���ȱ�����ǰ��������δ���ʹ����ڽӵ�
	    for(int i = 0; i < this.vertexNum; i++) {
	        if(this.weight[v][i] != INFINITY && !this.isVisited[i]) {
	            dfs(this.vertex[i]);
	        }
	    }
	}
	
	/**
	 * @brief  Floyd�㷨�����Դ���·��
	 * @param  dist: ���·������
	 */
	public void floyd(int[][] dist) {
	    // ���·�������ʼ��Ϊͼ���ڽӾ���
	    for(int i = 0; i < this.vertexNum; i++) {
	        for(int j = 0; j < this.vertexNum; j++) {
	            dist[i][j] = this.weight[i][j];
	        }
	    }

	    // Floyd�㷨
	    for(int k = 0; k < this.vertexNum; k++) {
	        for(int i = 0; i < this.vertexNum; i++) {
	            for(int j = 0; j < this.vertexNum; j++) {
	                if(dist[i][k] + dist[k][j] < dist[i][j]) {
	                    dist[i][j] = dist[i][k] + dist[k][j];
	                }
	            }
	        }
	    }
	}

	/**
	 * @brief  ��ӡ���·������
	 * @param  dist: ���·������
	 */
	public void printShortestDistance(int[][] dist) {
	    // ���������������
	    for(int i = 0; i < this.vertexNum; i++) {
	    	System.out.print(String.format("\t%2c", this.vertex[i]));
	    }
	    System.out.println();
	    for(int i = 0; i < this.vertexNum * MAX; i++) {
	        System.out.print("-");
	    }
	    System.out.println();
	    
	    for(int i = 0; i < this.vertexNum; i++) {
	    	System.out.print(String.format("%2c", this.vertex[i]));
	    	for(int j = 0; j < this.vertexNum; j++) {
	    		System.out.print("\t");
	    		if(dist[i][j] == INFINITY) {
	    			System.out.print(String.format("%2s", "��"));
	    		} else {
	    			System.out.print(String.format("%2d", dist[i][j]));
	    		}
	    		System.out.print("|");
	    	}
	    	System.out.println();
	    }
	}
	
	public static void main(String[] args) {
		Graph graph = new Graph();		// ����ͼ
		
		graph.printGraph();				// ��ӡ�ڽӾ���
		
		graph.clearFlag();
		System.out.print("������ȱ�����");
		graph.dfs('A');					// ָ��Դ�㿪ʼdfs
		System.out.println();
		
		// Floyd�㷨�����Դ���·��
	    int[][] dist = new int[MAX][MAX];
	    graph.floyd(dist);
	    System.out.println("��Դ���·����");
	    graph.printShortestDistance(dist);
	}
}
