#include<iostream>

using namespace std;

struct Node {
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};

Node * searchNode(Node * root, int value) {
	Node * rightResult;
	Node * leftResult;
	if (root == NULL) {
		return NULL;
	}
	else if (root->value == value) {
		return root;
	}
	else {
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL) {
			return NULL;
		}
		else if (rightResult != NULL) {
			return rightResult;
		}
		else {
			return leftResult;
		}
	}
}

void insertLeft(Node * Parent, Node * nodeToInsert)
{
	if (Parent->leftNode == NULL)
	{
		Parent->leftNode = nodeToInsert;
	}
	else
	{
		cout << "There is already a node there, unable to insert" << endl; 
	}
}

void insertRight(Node * Parent, Node * nodeToInsert)
{
	if (Parent->rightNode == NULL)
	{
		Parent->rightNode = nodeToInsert;
	}
	else
	{
		cout << "There is already a node there, unable to insert" << endl;
	}

}
//This searches through the tree left, root, right
int inOrderTransversal(Node * root)
{
	if (root != NULL) {
		inOrderTransversal(root->leftNode);
		cout << root->value << endl;
		inOrderTransversal(root->rightNode);
	}
	return 0;
}
//This searches through the tree left, right, root
int postOrderTransversal(Node * root)
{
	if (root != NULL)
	{
		postOrderTransversal(root->leftNode);
		postOrderTransversal(root->rightNode);
		cout << root->value << endl;
	}
	return 0;
}
//This searches through the tree root, left, right
int preOrderTransversal(Node * root)
{
	if (root != NULL)
	{
		cout << root->value << endl;
		preOrderTransversal(root->leftNode);
		preOrderTransversal(root->rightNode);
	}
	return 0; 
}


int main() 
{
	//These add new nodes and assign them values 
	//Root of the tree
	Node * BinaryTree = new Node;
	BinaryTree->value = 5;
	//Right child of the root
	Node * tmp = new Node;
	tmp->value = 1;
	BinaryTree->rightNode = tmp;
	//Left child of the root
	tmp = new Node;
	tmp->value = 4;
	BinaryTree->leftNode = tmp;

	Node * searchResult = searchNode(BinaryTree, 4);
	//Left child of 4
	tmp = new Node;
	tmp->value = 10; 
	insertLeft(searchResult, tmp);
	//Right child of 4
	searchResult = searchNode(BinaryTree, 4);
	tmp = new Node;
	tmp->value = 15;
	insertRight(searchResult, tmp);
	//Left child of 15
	searchResult = searchNode(BinaryTree, 15);
	tmp = new Node;
	tmp->value = 8;
	insertLeft(searchResult, tmp);
	//Right child of 1
	searchResult = searchNode(BinaryTree, 1);
	tmp = new Node;
	tmp->value = 7;
	insertRight(searchResult, tmp);
	//Right child of 7
	searchResult = searchNode(BinaryTree, 7);
	tmp = new Node;
	tmp->value = 9;
	insertRight(searchResult, tmp);

	// Prints out the lists
	cout << "####InOrderTraversal####" << endl;
	inOrderTransversal(BinaryTree);

	cout << "####PostOrderTraversal####" << endl;
	postOrderTransversal(BinaryTree);

	cout << "####PreOrderTraversal####" << endl;
	preOrderTransversal(BinaryTree);

	system("pause");
	return 0;
}
