#include <bits/stdc++.h>
using namespace std;
/*
Circular Queue.

*/
struct node{
	int val;
	node* next;
	node(int x) : val(x), next(NULL) {}
};

class Queue{
private:
	node *head;
public:
	Queue(){
		head = NULL;
	}

	void insert(int x){
		// empty.
		if(head == NULL){
			head = new node(x);
			head->next = head;
			return ;
		}
		// if size > 1.
		node *temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = new node(x);
		temp = temp->next;
		temp->next = head;
	}

	void dequeue(){
		if(head == NULL){
			cout<<"Queue is empty\n";
			return;
		}
		// if size = 1
		if(head->next == head){
			cout<<head->val<<" is deleted.\n";
			delete head;
			head = NULL;
			return;
		}
		cout<<head->val<<" is deleted.\n";
		head->val = head->next->val;
		node *temp = head->next;
		head->next = head->next->next;
		delete temp;
	}

	void delete_val(int x){
		if(head == NULL){
			cout<<"Queue is empty\n";
			return;
		}
		if(head->val == x){
			dequeue();
			return;
		}
		node* temp = head->next;
		while(temp !=head){
			if(temp->val == x){
				cout<<x<<" is deleted.\n";
				temp->val = temp->next->val;

				node* del = temp->next;
				
				temp->next = temp->next->next;
				delete del;
				return;
			}
			temp = temp->next;
		}
		cout<<x<<" not found.\n";
	}
	void traverse(){
		if(head==NULL){
			cout<<"Queue is empty.\n";
			return;
		}
		node * temp = head->next;

		cout<<head->val<<"->";
		while(temp != head){
			cout<<temp->val<<"->";
			temp=temp->next;
		}
		cout<<"\n";
	}
	void delete_alternate(){
		/*
		i/p: 1->2->3->4->
		o/p: 2->4->
		*/
		if(head == NULL||head->next == head){
			dequeue();
			return;
		}
		node *prevhead = head;
		head = head->next;
		cout<<prevhead->val<<" is deleted.\n";
		node* temp = head;
		while(temp!=prevhead && temp->next != prevhead){
			node* del = temp->next;
			temp->next = temp->next->next;
			cout<<del->val<<" is deleted\n";
			delete del;
			if(temp->next == prevhead){
				temp->next = head;
				delete prevhead;
				return;
			}
			temp = temp->next;
		}
		// here temp->next is prevhead.
		temp->next = head;
		delete prevhead;
		return;
	}
};

int main(void){
	Queue *q = new Queue();
	q->insert(1);
	q->insert(2);
	q->insert(3);
	q->insert(4);
	q->insert(5);
	q->traverse();
	q->delete_val(3);
	q->traverse();
	q->delete_alternate();
	q->traverse();
	
}
