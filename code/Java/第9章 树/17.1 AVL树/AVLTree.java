public class AVLTree<T extends Comparable<T>> {
	private AVLNode<T> root;
	private static final int SPACES = 4;

	private class AVLNode<T extends Comparable<T>> {
		T data;
		int height;
		AVLNode<T> left;
		AVLNode<T> right;

		public AVLNode(T data, AVLNode<T> left, AVLNode<T> right) {
			this.data = data;
			this.height = 0;
			this.left = left;
			this.right = right;
		}
	}

	public AVLTree() {
		root = null;
	}

	private int height(AVLNode<T> tree) {
		return tree == null ? 0 : tree.height;
	}

	public int height() {
		return height(root);
	}

	private void preOrder(AVLNode<T> tree) {
		if(tree != null) {
			System.out.print(tree.data + " ");
			preOrder(tree.left);
			preOrder(tree.right);
		}
	}

	public void preOrder() {
		preOrder(root);
	}

	private void inOrder(AVLNode<T> tree) {
		if(tree != null) {
			inOrder(tree.left);
			System.out.print(tree.data + " ");
			inOrder(tree.right);
		}
	}

	public void inOrder() {
		inOrder(root);
	}

	private void postOrder(AVLNode<T> tree) {
		if(tree != null) {
			postOrder(tree.left);
			postOrder(tree.right);
			System.out.print(tree.data + " ");
		}
	}

	public void postOrder() {
		postOrder(root);
	}

	private void indent(int level) {
		for(int i = 0; i < level * SPACES; i++) {
			System.out.print(" ");
		}
	}

	private void printTree(AVLNode<T> tree, int level, String type) {
		if(tree != null) {
			indent(level);
			level++;
			System.out.println("|__ " + tree.data + type);
			printTree(tree.left, level, "L");
			printTree(tree.right, level, "R");
		}
	}

	public void printTree() {
		printTree(root, 0, "");
	}

	private AVLNode<T> search(AVLNode<T> tree, T key) {
		while(tree != null) {
			int cmp = key.compareTo(tree.data);
			if(cmp < 0) {
				tree = tree.left;
			} else if(cmp > 0) {
				tree = tree.right;
			} else {
				return tree;
			}
		}
		return null;
	}

	public AVLNode<T> search(T key) {
		return search(root, key);
	}

	private AVLNode<T> getMin(AVLNode<T> tree) {
		if(tree == null) {
			return null;
		}
		while(tree.left != null) {
			tree = tree.left;
		}
		return tree;
	}

	private AVLNode<T> getMax(AVLNode<T> tree) {
		if(tree == null) {
			return null;
		}
		while(tree.right != null) {
			tree = tree.right;
		}
		return tree;
	}

	private AVLNode<T> LLRotation(AVLNode<T> k2) {
		AVLNode<T> k1 = k2.left;
		k2.left = k1.right;
		k1.right = k2;

		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.left), k2.height) + 1;
		return k1;
	}

	private AVLNode<T> RRRotation(AVLNode<T> k1) {
		AVLNode<T> k2 = k1.right;
		k1.right = k2.left;
		k2.left = k1;

		k1.height = Math.max(height(k1.left), height(k1.right)) + 1;
		k2.height = Math.max(k1.height, height(k2.right)) + 1;
		return k2;
	}

	private AVLNode<T> LRRotation(AVLNode<T> k3) {
		k3.left = RRRotation(k3.left);
		return LLRotation(k3);
	}

	private AVLNode<T> RLRotation(AVLNode<T> k1) {
		k1.right = LLRotation(k1.right);
		return RRRotation(k1);
	}

	private AVLNode<T> insert(AVLNode<T> tree, T val) {
		if(tree == null) {
			tree = new AVLNode<T>(val, null, null);
			tree.height = 1;
			return tree;
		}

		int cmp = val.compareTo(tree.data);
		if(cmp < 0) {
			tree.left = insert(tree.left, val);
			if(height(tree.left) - height(tree.right) == 2) {
				if(val.compareTo(tree.left.data) < 0) {
					tree = LLRotation(tree);
				} else {
					tree = LRRotation(tree);
				}
			}
		} else {
			tree.right = insert(tree.right, val);
			if(height(tree.right) - height(tree.left) == 2) {
				if(val.compareTo(tree.right.data) > 0) {
					tree = RRRotation(tree);
				} else {
					tree = RLRotation(tree);
				}
			}
		}

		tree.height = Math.max(height(tree.left), height(tree.right)) + 1;
		return tree;
	}

	public void insert(T val) {
		root = insert(root, val);
	}

	private AVLNode<T> delete(AVLNode<T> tree, AVLNode<T> del) {
		if(tree == null || del == null) {
			return null;
		}

		int cmp = del.data.compareTo(tree.data);
		if(cmp < 0) {
			tree.left = delete(tree.left, del);
			if(height(tree.right) - height(tree.left) == 2) {
				AVLNode<T> rightNode = tree.right;
				if(height(rightNode.left) > height(rightNode.right)) {
					tree = RLRotation(tree);
				} else {
					tree = RRRotation(tree);
				}
			}
		} else if(cmp > 0) {
			tree.right = delete(tree.right, del);
			if(height(tree.left) - height(tree.right) == 2) {
				AVLNode<T> leftNode = tree.left;
				if(height(leftNode.right) > height(leftNode.left)) {
					tree = LRRotation(tree);
				} else {
					tree = LLRotation(tree);
				}
			}
		} else {
			if(tree.left != null && tree.right != null) {
				if(height(tree.left) > height(tree.right)) {
					// 如果左子树比右子树高：
					// 1. 找出左子树的最大结点
					// 2. 将最大结点的值赋给tree
					// 3. 删除最大结点
					AVLNode<T> max = getMax(tree.left);
					tree.data = max.data;
					tree.left = delete(tree.left, max);
				} else {
					// 如果右子树比左子树高（或相等）：
					// 1. 找出右子树的最小结点
					// 2. 将最小结点的值赋给tree
					// 3. 删除最小结点
					AVLNode<T> min = getMin(tree.right);
					tree.data = min.data;
					tree.right = delete(tree.right, min);
				}
			} else {
				tree = tree.left != null ? tree.left : tree.right;
			}
		}
		return tree;
	}

	public void delete(T key) {
		AVLNode<T> del = search(key);
		if(del != null) {
			root = delete(root, del);
		}
	}
}
