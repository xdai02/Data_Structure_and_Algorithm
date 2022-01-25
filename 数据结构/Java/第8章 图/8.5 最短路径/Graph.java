import java.util.Scanner;

public class Graph {
	private final static int MAX = 10;			// 最大顶点数
	private final static int INFINITY = 65535;	// 无穷大
	
	private final static int UNDIRECTED = 0;	// 无向图
	private final static int DIRECTED = 1;		// 有向图
	
	private int type;				// 图的类型（无向图-0 / 有向图-1）
	private char[] vertex;			// 顶点名称
	private int vertexNum;			// 顶点数量
	private int edgeNum;			// 边数量
	private int[][] weight;			// 邻接矩阵
	
	private boolean[] isVisited;	// 访问标志
	
	/**
	 * @brief  创建图
	 * 指定格式输入图的信息（txt文件提供样例）
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
		System.out.print("图的类型（无向图-0 / 有向图-1）：");
		this.type = scanner.nextInt();
		
		System.out.print("图的顶点数量：");
		this.vertexNum = scanner.nextInt();
		for(int i = 0; i < this.vertexNum; i++) {
			System.out.print("输入第" + (i+1) + "个顶点名称：");
			this.vertex[i] = scanner.next().charAt(0);
		}
		
		System.out.print("图的边数量：");
		this.edgeNum = scanner.nextInt();
		for(int i = 0; i < this.edgeNum; i++) {
			char src, dst;          // 起始顶点 目标顶点
	        int weight;             // 边的权值
	        int v1, v2;             // 起始顶点下标 目标顶点下标
	        
			System.out.print("输入第" + (i+1) + "条边信息（起始顶点 目标顶点 权值）：");
	        src = scanner.next().charAt(0);
	        dst = scanner.next().charAt(0);
	        weight = scanner.nextInt();
	        
	        // 在已有的顶点中查找顶点下标
	        for(v1 = 0; src != this.vertex[v1]; v1++);
	        for(v2 = 0; dst != this.vertex[v2]; v2++);
	        this.weight[v1][v2] = weight;
        	// 无向图在对角保存相同权值
	        if(this.type == UNDIRECTED) {
	        	this.weight[v2][v1] = weight;
	        }
		}	
		scanner.close();
	}
	
	/**
	 * @brief  输出图的邻接矩阵
	 */
	public void printGraph() {
		// 首行输出顶点名称
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
	    			System.out.print(String.format("%2s", "∞"));
	    		} else {
	    			System.out.print(String.format("%2d", this.weight[i][j]));
	    		}
	    		System.out.print("|");
	    	}
	    	System.out.println();
	    }
	}
	
	/**
	 * @brief  清空顶点的访问标志isVisited
	 */
	public void clearFlag() {
	    for(int i = 0; i < MAX; i++) {
	        this.isVisited[i] = false;
	    }
	}
	
	/**
	 * @brief  深度优先遍历
	 * @param  v: 开始遍历的顶点
	 */
	public void dfs(char vertex) {
	    // 在已有的顶点中查找顶点下标
	    int v;
	    for(v = 0; vertex != this.vertex[v]; v++);

	    // 访问当前顶点
	    System.out.print("-> " + this.vertex[v] + " ");
	    this.isVisited[v] = true;

	    // 递归深度遍历当前顶点所有未访问过的邻接点
	    for(int i = 0; i < this.vertexNum; i++) {
	        if(this.weight[v][i] != INFINITY && !this.isVisited[i]) {
	            dfs(this.vertex[i]);
	        }
	    }
	}
	
	/**
	 * @brief  Floyd算法计算多源最短路径
	 * @param  dist: 最短路径矩阵
	 */
	public void floyd(int[][] dist) {
	    // 最短路径矩阵初始化为图的邻接矩阵
	    for(int i = 0; i < this.vertexNum; i++) {
	        for(int j = 0; j < this.vertexNum; j++) {
	            dist[i][j] = this.weight[i][j];
	        }
	    }

	    // Floyd算法
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
	 * @brief  打印最短路径矩阵
	 * @param  dist: 最短路径矩阵
	 */
	public void printShortestDistance(int[][] dist) {
	    // 首行输出顶点名称
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
	    			System.out.print(String.format("%2s", "∞"));
	    		} else {
	    			System.out.print(String.format("%2d", dist[i][j]));
	    		}
	    		System.out.print("|");
	    	}
	    	System.out.println();
	    }
	}
	
	public static void main(String[] args) {
		Graph graph = new Graph();		// 创建图
		
		graph.printGraph();				// 打印邻接矩阵
		
		graph.clearFlag();
		System.out.print("深度优先遍历：");
		graph.dfs('A');					// 指定源点开始dfs
		System.out.println();
		
		// Floyd算法计算多源最短路径
	    int[][] dist = new int[MAX][MAX];
	    graph.floyd(dist);
	    System.out.println("多源最短路径：");
	    graph.printShortestDistance(dist);
	}
}
