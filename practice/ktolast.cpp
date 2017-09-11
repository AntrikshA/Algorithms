#include <iostream>
#include <map>

using namespace std;

// Implement an algorithm to find the kth to last element of a singly linked list.

struct node{
	int value;
	struct node* next;
};

struct node* newNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->value = data;
	node->next = NULL;
	return node;
}

void insert(struct node** root, int a){
	struct node *temp = *root;
	if(*root == NULL){
		*root = newNode(a);
		return;
	}
	
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode(a);
	return;
}

void print(struct node* root){
	struct node* temp = root;

	while(temp!=NULL){
		cout << temp->value << endl;
		temp = temp->next;
	}
}

void remove(struct node** root, int value){
	struct node *temp = *root;
	if(*root == NULL){
		cout  << "Linked list empty" <<endl;
		return;
	}
	while(temp->next->value != value){
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return;
}

void find(struct node ** root, int k){
	struct node * fwdptr = *root;
	struct node * bwdptr = *root;

	while(k){
		fwdptr = fwdptr->next;
		k--;
		if(fwdptr==NULL){
			cout << "Not enough elements in list" << endl;
			return;
		}
	}

	while(fwdptr!=NULL){
		bwdptr = bwdptr->next;
		fwdptr = fwdptr->next;
	}

	print(bwdptr);
	return;

}

int main(){

	int array[] = {2, 4, 5, 7, 1, 9, 6, 8, 0, 3, 2};

	struct node* root=NULL;
	for(int i=0;i<11;i++){
		insert(&root, array[i]);
	}
	remove(&root, 3);

	int k;
	cout << "k: ";
	cin >> k;

	find(&root, k);

	// print(root);

}