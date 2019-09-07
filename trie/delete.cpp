#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
	struct TrieNode *children[26];
	bool isEow;
};

TrieNode *getNode(){
	TrieNode* node = new TrieNode;
	node->isEow = false;

	for(int i=0; i<26; i++)
		node->children[i] = NULL;

	return node;
}

void insert(TrieNode* root, string s){
	TrieNode* temp = root;
	int n = s.size();
	for(int i=0; i<n; i++){
		int x = s[i] - 'a';
		if(!temp->children[x])
			temp->children[x] = getNode();
		temp = temp->children[x];
	}
	temp->isEow = true;
}

bool search(TrieNode* root, string s){
	TrieNode* temp = root;
	int n = s.size();
	for(int i=0; i<n; i++){
		int x = s[i] - 'a';
		if(!temp->children[x])
			return false;
		temp = temp->children[x];
	}

	return (temp!=NULL && temp->isEow);
}

bool isEmpty(TrieNode* root){
	for(int i=0; i < 26; i++)
		if(root->children[i])
			return false;
	return true;
}

TrieNode* remove(TrieNode* root, string key, int depth=0){
	if(!root)
		return NULL;
	// if last char of the key is being processed.
	if(depth == key.size()){
		if(root->isEow)
			root->isEow = false;

		if(isEmpty(root)){
			delete(root);
			root = NULL;
		}

		return root;
	}

	// if not last char, recur for the child
	int ind = key[depth] - 'a';
	root->children[ind] = remove(root->children[ind], key, depth+1);

	if(isEmpty(root) && root->isEow == false){
		delete(root);
		root = NULL;
	}
	return root;
}

int main(void){
	string keys[] = {"the", "a", "there", 
	                    "answer", "any", "by", 
	                     "bye", "their", "hero", "heroplane"};
	int n = sizeof(keys)/sizeof(keys[0]);
	TrieNode *root = getNode();

	for(int i=0; i<n; i++)
		insert(root, keys[i]);

	search(root, "the")? cout << "Yes\n" : 
	                     cout << "No\n"; 
	search(root, "these")? cout << "Yes\n" : 
	                       cout << "No\n"; 

	search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
	remove(root, "heroplane"); 
	search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
	search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
}