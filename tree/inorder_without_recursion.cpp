#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

void inorder(Node *root){
	Node *curr = root;
	stack<Node*> s;
	while(curr!=NULL || s.empty() == false){
		while(curr){
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();

		cout<< curr->data <<" ";
		curr = curr->right;
	}
}

int main(void){
	struct Node *root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5);
	cout << "\nInorder traversal of binary tree is \n"; 
	inorder(root); 
}