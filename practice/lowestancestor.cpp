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

bool side(struct node* root, int value){
	// cout << "here at " << value << end << endl;
	if(root==NULL)	return false;
	if(root->value == value)	return true;
	return (side(root->right, value) || side(root->left, value));
}

struct node* firstAncestor(struct node* root, int one, int two){

	//Base
	if(root==NULL) return NULL;
	if(root->value==one || root->value==two) return root;

	bool oneleft = side(root->left, one);
	bool twoleft = side(root->left, two);
	// cout << oneleft << " " << twoleft << endl;

	if(oneleft && twoleft){
		return firstAncestor(root->left, one, two);
	}
	else if(!oneleft && !twoleft){
		return firstAncestor(root->right, one, two);
	}
	else{
		return root;
	}

}

int main(){
	int array[] = {2, 5, 6, 1, 3, 4, 7, 9, 0, 2};

	struct node* root= NULL;
	for(int i=0;i<10;i++){
		insert(&root, array[i]);
		
	}
	inorder(root);
	cout << endl;

	struct node *ancestor = firstAncestor(root, 7, 9);	
	cout << ancestor->value << endl;

	// inorder(root);
	// cout << endl;
	return 0;
}