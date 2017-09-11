#include <iostream>
#include <map>

using namespace std;

// Implement an algorithm to delete a node in the middle of a singly linked list, given
// only access to that node

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

struct node* find(struct node ** root, int k){
	struct node * fwdptr = *root;
	struct node * bwdptr = *root;

	if(root==NULL)return NULL;
	if(k<=0)return NULL;

	while(k){
		fwdptr = fwdptr->next;
		k--;
		if(fwdptr==NULL){
			cout << "Not enough elements in list" << endl;
			return NULL;
		}
	}

	while(fwdptr!=NULL){
		bwdptr = bwdptr->next;
		fwdptr = fwdptr->next;
	}
	// print(bwdptr);
	return bwdptr;

}

void delet(struct node ** middle){
	struct node* temp = *middle;
	if(temp==NULL || temp->next==NULL){
		cout << "No node to remove::cannot remove the last node" << endl;
		return;
	}

	struct node* n = temp->next;
	temp->value = n->value;
	temp->next = n->next;

	return;
}

void partition(struct node** root, struct node ** middle){

	struct node* lesslist = NULL;
	struct node* equalist = NULL;
	struct node* morelist = NULL;

	struct node* temp = *root;
	struct node *pivot = *middle;

	while(temp!=NULL){
		if(temp->value<pivot->value){
			insert(&lesslist, temp->value);
		}
		else if(temp->value==pivot->value){
			insert(&equalist, temp->value);	
		}
		else if(temp->value>pivot->value){
			insert(&morelist, temp->value);
		}
		temp = temp->next;
	}

	*root = lesslist;
	temp = *root;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = equalist;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = morelist;

	// cout << "Here" << endl;
	print(*root);

}

int main(){

	int array[] = {2, 4, 5, 7, 1, 9, 6, 8, 0, 3, 2, 6};

	struct node* root=NULL;
	for(int i=0;i<12;i++){
		insert(&root, array[i]);
	}
	// remove(&root, 3);

	int k;
	cout << "k: ";
	cin >> k;

	struct node *middle = find(&root, k);

	// delet(&middle);
	partition(&root, &middle);

	// print(root);

	// print(root);
	return 0;

}