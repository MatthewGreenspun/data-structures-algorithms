#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node* left;
	struct node* right;
};
typedef struct node node_t;

node_t* makeNode(int val){
	node_t* n = malloc(sizeof(node_t));
	n->val = val;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void addNode(node_t* node, int val){
	if(val < node->val && node->left == NULL)
		node->left = makeNode(val);
	else if (val < node->val && node->left != NULL)
		addNode(node->left, val);
	else if(val > node->val && node->right == NULL)
		node->right = makeNode(val);
	else if (val > node->val && node->right != NULL)
		addNode(node->right, val);
}

void freeTree(node_t* root) {
	node_t* left = root->left;
	node_t* right = root->right;
	free(root);
	if(left != NULL) freeTree(left);
	if(right != NULL) freeTree(right);
}
 
void printTree(node_t* node, int level){
	if(node == NULL) return;
	printTree(node->right, level + 1);
	int i;
	for(i = 0; i < level * 10; i++)
		printf(" ");
	printf("%d\n", node->val);

	printTree(node->left, level + 1);
}

int main(){
	node_t* bst = makeNode(4);
	addNode(bst, 2);
	addNode(bst, 5);
	addNode(bst, 1);
	addNode(bst, 9);
	addNode(bst, 8);
	addNode(bst, 7);
	addNode(bst, -2);
	addNode(bst, 20);
	addNode(bst, 10);
	addNode(bst, -9);
	addNode(bst, -4);

	printTree(bst, 0);
	freeTree(bst);
	return 0;
}
