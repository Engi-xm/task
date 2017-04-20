#include <stdlib.h>
#include <stdio.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
typedef struct Node node_t;

node_t* new_node(int data) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int sum_binary_tree(node_t* root) {
	if(root == NULL) 
		return 0;
	return root->data + sum_binary_tree(root->left) + sum_binary_tree(root->right);
}

int main(void) {
	node_t* root = 		new_node(2);
	root->left = 		new_node(5);
	root->right = 		new_node(7);
	root->left->left = 	new_node(10);
	root->left->right = 	new_node(2);
	root->right->right = 	new_node(4);
	
	printf("sum binary tree = %d \n", sum_binary_tree(root));
	
	return 0;
}
