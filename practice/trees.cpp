#include <iostream>

using namespace std;

struct node{
	int value;
	struct node *left, *right;
};

struct node * newNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->value = data;
	node->left = node->right = NULL;
	return node;
}

void insert(struct node** root, int data){
	struct node* temp = *root;

	if(*root==NULL){
		*root = newNode(data);
		return;
	}

	if(temp->value>data){
		insert(&temp->left, data);
	}
	else{
		insert(&temp->right, data);
	}
}

void inorder(struct node *root){
	if(root==NULL) return;

	inorder(root->left);
	cout << root->value << " ";
	inorder(root->right);

	return;

}

int main(){
	int array[] = {2, 5, 6, 1, 3, 4, 7, 9, 0, 2};

	struct node* root= NULL;
	for(int i=0;i<10;i++){
		insert(&root, array[i]);
		inorder(root);
		cout << endl;
	}

	inorder(root);
	cout << endl;
	return 0;
}