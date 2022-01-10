/*
file esercizio34.cpp
compilare con: g++ -std=c++11 esercizio34.cpp
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

class BinaryTree {
	public:
		struct Node {
			int value;
			Node *right, *left;
			Node(int);
		};

	private:
		Node *root;

	public:
		BinaryTree(int);
		void insert(int);
		bool contains(int);
		void remove(int value);
		string to_str() const;

	private:
		void insertRec(int, Node*);
		bool containsInternal(int, Node*);
		Node* removeInternal(int, Node*);
		int min(Node* node);
		bool isTerminal(Node* node);
		void traversePreOrder(string& sb, string& spacing, string& ptr, Node* node, bool right) const;

	friend std::ostream& operator<<(std::ostream&, const BinaryTree&);
};

BinaryTree::Node::Node(int value) {
	this->value = value;
}

BinaryTree::BinaryTree(int rootValue) {
	this->root = new Node(rootValue);
}

void BinaryTree::insert(int value) {
	insertRec(value, this->root);
}

void BinaryTree::insertRec(int value, Node *node) {
	if (value < node->value) {
		if (node->left != NULL) {
			insertRec(value, node->left);
		}
		else {
			node->left = new Node(value);
		}
	}
	else if (value > node->value) {
		if (node->right != NULL) {
			insertRec(value, node->right);
		}
		else {
			node->right = new Node(value);
		}
	}
}

bool BinaryTree::containsInternal(int value, Node* node) {
	if (node == NULL) return false;
	if (value == node->value) return true;
	return value < node->value ? containsInternal(value, node->left) : containsInternal(value, node->right);
}

bool BinaryTree::contains(int value) {
	return containsInternal(value, root);
}

void BinaryTree::remove(int value) {
	root = removeInternal(value, root);
}

BinaryTree::Node* BinaryTree::removeInternal(int value, Node* node) {
	if (node == NULL) return NULL;

	// prima di cancellare un nodo, occorre assegnare il suo valore al nodo padre
	if (value == node->value) {
		if (isTerminal(node)) return NULL;

		if (node->left != NULL) return node->left;
		if (node->right != NULL) return node->right;

		// caso 3: il nodo ha tutt'e due i membri valorizzati
		int minVal = min(node->right);
		node->value = minVal;
		node->right = removeInternal(minVal, node->right);
		return node;
	}

	if (value < node->value) {
		node->left = removeInternal(value, node->left);
		return node;
	}

	node->right = removeInternal(value, node->right);

	return node;
}

int BinaryTree::min(Node* node) {
	return node->left == NULL ? node->value : min(node->left);
}

bool BinaryTree::isTerminal(Node* node) {
	return node->left == NULL && node->right == NULL;
}

string BinaryTree::to_str() const {
	string s = to_string(root->value);
	string pSup = "\\__";
	string pInf = root->right != NULL ? "|--" : "\\__";
	string spacing("");
	traversePreOrder(s, spacing, pInf, root->left, root->right != NULL);
	traversePreOrder(s, spacing, pSup, root->right, false);

	return s;
}

void BinaryTree::traversePreOrder(string& s, string& spacing, string& ptr, Node* node, bool right) const {
	if (node == NULL) return;

	s += "\n";
	s += spacing;
	s += ptr;
	s += to_string(node->value);

	string r = right ? ":  " : "   ";
	string totSp = spacing + r;

	string pSup = "\\__";
	string pInf = node->right != NULL ? "|--" : "\\__";

	traversePreOrder(s, totSp, pInf, node->left, (node->right != NULL));
	traversePreOrder(s, totSp, pSup, node->right, false);
}

ostream& operator<<(ostream& os, const BinaryTree& tree) {
	os << tree.to_str();
	return os;
}

int main() {
	BinaryTree tree(10);

	tree.insert(5);
	tree.insert(7);
	tree.insert(9);
	tree.insert(3);
	tree.insert(15);
	tree.insert(12);
	tree.insert(17);

	cout << tree << endl;

	if (tree.contains(7)) {
		cout << "Il numero 7 sarà rimosso dall'albero binario." << endl;
		tree.remove(7);
	}

	cout << tree << endl;
}

