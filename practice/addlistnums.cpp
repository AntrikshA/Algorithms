#include <iostream>
#include <map>

using namespace std;

// You have two numbers represented by a linked list, where each node contains a
// single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
// of the list. Write a function that adds the two numbers and returns the sum as a
// linked list.

// FOLLOW UP

// Suppose the digits are stored in forward order. Repeat the above problem.

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
		cout << temp->value << "->";
		temp = temp->next;
	}
	cout << endl;
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

struct node* addlists(struct node* list1, struct node* list2, int carry){
	if(list1==NULL && list2==NULL && carry==0){
		return NULL;
	}

	struct node* newlist = newNode(carry);
	struct node* list1next = NULL;
	struct node* list2next = NULL;

	if(list1!=NULL)
		carry += list1->value;
	if(list2!=NULL)
		carry += list2->value;

	newlist->value = carry%10;
	print(newlist);
	carry = carry>=10;

	// AVOIDS SEGFAULT
	if(list2 == NULL)
		list2next = NULL;
	else
		list2next = list2->next;
	if(list1 ==NULL)
		list1next= NULL;
	else
		list1next = list1->next;

	if(list1!=NULL || list2!=NULL){
		struct node* nextlist = newlist->next = addlists(list1next, list2next, carry);
		newlist->next = nextlist;
	}
	return newlist;

}

void partition(struct node** root, struct node ** middle){

	struct node* lesslist = NULL;
	struct node* morelist = NULL;

	struct node* temp = *root;
	struct node *pivot = *middle;

	while(temp!=NULL){
		if(temp->value<pivot->value){
			insert(&lesslist, temp->value);
		}
		else if(temp->value>=pivot->value){
			insert(&morelist, temp->value);
		}
		temp = temp->next;
	}

	// *root = lesslist;
	// temp = *root;
	// while(temp->next!=NULL){
	// 	temp = temp->next;
	// }
	// temp->next = equalist;
	// while(temp->next!=NULL){
	// 	temp = temp->next;
	// }
	// temp->next = morelist;

	print(lesslist);
	print(morelist);

	struct node* newlist = addlists(lesslist, morelist, 0);

	cout << "\nPrinting list" << endl;
	print(newlist);
	// cout << "Here" << endl;
	// print(*root);
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