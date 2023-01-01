/* file Esercizio35.java */

class BinaryTree<T extends Comparable<T>> {
	static class Node<T> {
		T value;
		Node<T> right, left; 

		public Node(T value) {
			this.value = value;
		}

		@Override
		public String toString() {
			return this.value.toString();
		}
	}

	private Node<T> root;

	public BinaryTree(T rootValue) {
		this.root = new Node<T>(rootValue);
	}

	public void insert(T value) {
		insertRec(value, root);
	}

	private void insertRec(T value, Node<T> node) {
		// <
		if (value.compareTo(node.value) < 0) {
			if (node.left != null) {
				insertRec(value, node.left);
			}
			else {
				node.left = new Node<T>(value);
			}
		}
		// >
		else if (value.compareTo(node.value) > 0) {
			if (node.right != null) {
				insertRec(value, node.right);
			}
			else {
				node.right = new Node<T>(value);
			}
		}
	}

	private boolean containsInternal(T value, Node<T> node) {
		if (node == null) return false;
		if (value == node.value) return true;
		return value.compareTo(node.value) < 0 ? containsInternal(value, node.left) : containsInternal(value, node.right);
	}

	public boolean contains(T value) {
		return containsInternal(value, root);
	}

	// soppressi i warning dovuti al meccanismo di type erasure
	@SuppressWarnings("unchecked")
	public void remove(T value) {
		root = removeInternal(value, root);
	}

	// soppressi i warning dovuti al meccanismo di type erasure
	@SuppressWarnings("unchecked")
	private Node removeInternal(T value, Node<T> node) {
		if (node == null) return null;

		// prima di cancellare un nodo, occorre assegnare il suo valore al nodo padre
		if (value.equals(node.value)) {
			if (isTerminal(node)) return null;

			if (node.left != null) return node.left;
			if (node.right != null) return node.right;

			// caso 3: il nodo ha tutt'e due i membri valorizzati
			T minVal = min(node.right);
			node.value = minVal;
			node.right = removeInternal(minVal, node.right);
			return node;
		}

		if (value.compareTo(node.value) < 0) {
			node.left = removeInternal(value, node.left);
			return node;
		}

		node.right = removeInternal(value, node.right);
		return node;
	}

	private T min(Node<T> node) {
		return node.left == null ? node.value : min(node.left);
	}

	private boolean isTerminal(Node<T> node) {
		return node.left == null && node.right == null;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(root.value);
		String pSup = "\\__";
		String pInf = root.right != null ? "|--" : "\\__";
		traversePreOrder(sb, "", pInf, root.left, root.right != null);
		traversePreOrder(sb, "", pSup, root.right, false);

		return sb.toString();
	}

	private void traversePreOrder(StringBuilder sb, String spacing, String ptr, Node node, boolean right) {
		if (node == null) return;

		sb.append(System.lineSeparator());
		sb.append(spacing);
		sb.append(ptr);
		sb.append(node.value);

		String r = right ? ":  " : "   ";
		StringBuilder spBuilder = new StringBuilder(spacing);
		spBuilder.append(r);

		String totSp = spBuilder.toString();
		String pSup = "\\__";
		String pInf = node.right != null ? "|--" : "\\__";

		traversePreOrder(sb, totSp, pInf, node.left, node.right != null);
		traversePreOrder(sb, totSp, pSup, node.right, false);
	}
}

public class Esercizio35 {
	public static void main(String [] args) {
		BinaryTree<Integer> tree = new BinaryTree<Integer>(10);

		tree.insert(5);
		tree.insert(7);
		tree.insert(9);
		tree.insert(3);
		tree.insert(15);
		tree.insert(12);
		tree.insert(17);

		System.out.println(tree);

		if (tree.contains(7)) {
			System.out.println("Il numero 7 sarà rimosso dall'albero binario.");
			tree.remove(7);
		}

		System.out.println(tree);
	}
}

