class Node {
	private int data;		// ������
	private Node left;		// ����
	private Node right;		// �Һ���
	
	public Node(int val) {
		this.data = val;
		this.left = null;
		this.right = null;
	}

	public Node(int data, Node left, Node right) {
		this.data = data;
		this.left = left;
		this.right = right;
	}
	
	public void setData(int data) {
		this.data = data;
	}

	public int getData() {
		return data;
	}

	public void setLeft(Node left) {
		this.left = left;
	}

	public Node getLeft() {
		return left;
	}

	public void setRight(Node right) {
		this.right = right;
	}

	public Node getRight() {
		return right;
	}
}

public class BinarySearchTree {
	private Node root;		// ����
	private final static int SPACES = 4;

	/**
	 * @brief  ��ʼ��������
	 * @param  val: ��Ԫ��
	 */
	public BinarySearchTree(int val) {
		this.root = new Node(val);
	}
	
	public void setRoot(Node root) {
		this.root = root;
	}
	
	public Node getRoot() {
		return this.root;
	}
	
	/**
	 * @brief  �������
	 * @param  node: ����
	 */
	public void preOrder(Node node) {
		if(node != null) {
			System.out.print(node.getData() + " ");
			preOrder(node.getLeft());
			preOrder(node.getRight());
		}
	}
	
	/**
	 * @brief  �������
	 * @param  node: ����
	 */
	public void inOrder(Node node) {
		if(node != null) {
			inOrder(node.getLeft());
			System.out.print(node.getData() + " ");
			inOrder(node.getRight());
		}
	}
	
	/**
	 * @brief  �������
	 * @param  node: ����
	 */
	public void postOrder(Node node) {
		if(node != null) {
			postOrder(node.getLeft());
			postOrder(node.getRight());
			System.out.print(node.getData() + " ");
		}
	}
	
	/**
	 * @brief  ��ӡ��ʾ��εĿո��
	 * @note   ������״��ӡ������
	 * @param  level: ���������
	 */
	public void indent(int level) {
	    for(int i = 0; i < SPACES * level; i++) {
	        System.out.print(".");
	    }
	}
	
	/**
	 * @brief  ��״��ӡ������
	 * @param  node: ����
	 * @param  level: ���������
	 */
	void showTree(Node node, int level) {
	    if(node == null) {
	        return;
	    }
	    indent(level);
	    System.out.println(node.getData());
	    level++;
	    showTree(node.getLeft(), level);
	    showTree(node.getRight(), level);
	    level--;
	}
	
	/**
	 * @brief  ����Ԫ��
	 * @param  node: ����
	 * @param  val: ����ֵ
	 * @retval ����������
	 */
	public Node insert(Node node, int val) {
		if(node == null) {
			return new Node(val);
		}
		
		if(val < node.getData()) {
			node.setLeft(insert(node.getLeft(), val));
		} else {
			node.setRight(insert(node.getRight(), val));
		}
		return node;
	}
	
	/**
	 * @brief  ����Ԫ��
	 * @param  node: ����
	 * @param  val: ����Ԫ��
	 * @retval Ԫ�����ڽ��ָ�룬�����ڷ���null
	 */
	public Node search(Node node, int val) {
		if(node == null) {
			return null;
		}
		
		if(val == this.root.getData()) {
			return this.root;
		} else if(val < this.root.getData()) {
			return search(this.root.getLeft(), val);
		} else {
			return search(this.root.getRight(), val);
		}
	}
	
	/**
	 * @brief  ��ȡ����
	 * @param  root: ����
	 * @retval ����
	 */
	public int getHeight(Node node) {
		if(node == null) {
			return 0;
		}
		return Math.max(getHeight(node.getLeft()), getHeight(node.getRight())) + 1;
	}

	public static void main(String[] args) {
		BinarySearchTree bst = new BinarySearchTree(5);
		Node root = bst.getRoot();
		
		bst.insert(root, 2);
		bst.insert(root, 7);
		bst.insert(root, 4);
		bst.insert(root, 9);
		bst.insert(root, 1);
		bst.insert(root, 6);
		bst.insert(root, 8);
		bst.insert(root, 3);
		
		System.out.print("preOrder: ");
	    bst.preOrder(root);
	    System.out.println();
	    
	    System.out.print("inOrder: ");
	    bst.inOrder(root);
	    System.out.println();
	    
	    System.out.print("postOrder: ");
	    bst.postOrder(root);
	    System.out.println();

	    bst.showTree(root, 0);
		System.out.println("height: " + bst.getHeight(root));
	}
}
