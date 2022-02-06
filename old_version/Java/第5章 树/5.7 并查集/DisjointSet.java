public class DisjointSet {
    private int[] parent;       // 父结点数组
    private int[] rank;         // 秩

    /**
     * 初始化每个元素的父结点
     * 初始时所有结点的父结点为自己本身
     * @param n - 元素数量
     */
    public DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    /**
     * 查询一个元素所在集合的根结点
     * @param val - 待查询元素
     * @return - 该集合根结点
     */
    public int find(int val) {
        if(parent[val] == val) {
            return val;
        } else {
            parent[val] = find(parent[val]);
            return parent[val];
        }
    }

    /**
     * 合并两个集合
     * @param i - 待合并元素1
     * @param j - 待合并元素2
     */
    public void merge(int i, int j) {
        // 找到对应根结点
        int x = find(i);
        int y = find(j);
        if(rank[x] <= rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
        }
        // 如果深度相同且根结点不同，则新的根结点深度+1
        if(rank[x] == rank[y] && x != y) {
            rank[y]++;
        }
    }

    public static void main(String[] args) {
        DisjointSet disjointSet = new DisjointSet(7);

        disjointSet.merge(3, 1);
        disjointSet.merge(2, 1);
        disjointSet.merge(5, 4);
        disjointSet.merge(6, 4);
        disjointSet.merge(4, 1);

        System.out.println(disjointSet.find(6));
    }
}
