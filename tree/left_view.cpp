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

void left_view(Node *root){
	if(root==NULL) return;
	Node *curr = root;
	queue<pair<Node*, int>> q;
	q.push({curr, 1});
	int i=0;
	while(!q.empty()){
		curr = q.front().first;
		int l = q.front().second;
		q.pop();
		if(l>i){
			cout<<curr->data<<" ";
			i=l;
		}
		if(curr->left)
			q.push({curr->left, l+1});
		if(curr->right)
			q.push({curr->right, l+1});
	}
 }

int main(void){
	struct Node *root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5);
	cout << "\nLeft of the Tree: \n"; 
	left_view(root); 
}