/* file Esercizio34.java */

class BinaryTree {
	static class Node {
		Integer value;
		Node right, left; // null per default

		public Node(Integer value) {
			this.value = value;
		}

		@Override
		public String toString() {
			return this.value.toString();
		}
	}

	private Node root;

	public BinaryTree(Integer rootValue) {
		this.root = new Node(rootValue);
	}

	public void insert(Integer value) {
		insertRec(value, root);
	}

	private void insertRec(Integer value, Node node) {
		// <
		if (value.compareTo(node.value) < 0) {
			if (node.left != null) {
				insertRec(value, node.left);
			}
			else {
				node.left = new Node(value);
			}
		}
		// >
		else if (value.compareTo(node.value) > 0) {
			if (node.right != null) {
				insertRec(value, node.right);
			}
			else {
				node.right = new Node(value);
			}
		}
	}

	private boolean containsInternal(Integer value, Node node) {
		if (node == null) return false;
		if (value == node.value) return true;
		return value.compareTo(node.value) < 0 ? containsInternal(value, node.left) : containsInternal(value, node.right);
	}

	public boolean contains(Integer value) {
		return containsInternal(value, root);
	}

	public void remove(Integer value) {
		root = removeInternal(value, root);
	}

	private Node removeInternal(Integer value, Node node) {
		if (node == null) return null;

		// prima di cancellare un nodo, occorre assegnare il suo valore al nodo padre
		if (value.equals(node.value)) {
			if (isTerminal(node)) return null;

			if (node.left != null) return node.left;
			if (node.right != null) return node.right;

			// caso 3: il nodo ha tutt'e due i membri valorizzati
			Integer minVal = min(node.right);
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

	private Integer min(Node node) {
		return node.left == null ? node.value : min(node.left);
	}

	private boolean isTerminal(Node node) {
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

public class Esercizio34 {
	public static void main(String [] args) {
		BinaryTree tree = new BinaryTree(10);

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

