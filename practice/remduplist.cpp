#include <iostream>
#include <map>

using namespace std;

// Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

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

int main(){

	int array[] = {2, 4, 5, 7, 1, 9, 6, 8, 0, 3, 2};

	struct node* root=NULL;
	for(int i=0;i<11;i++){
		insert(&root, array[i]);
	}
	remove(&root, 3);
	print(root);

}