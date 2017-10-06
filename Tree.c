#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Node;
typedef Node * node;
node tree;
void create_tree(node tree);
node insert_ele(node tree,int val);
void inorder_tra(node tree);
void preorder_tra(node tree);
void postorder_tra(node tree);
node findSmallest(node tree);
node findLargest(node tree);
node delete_ele(node tree,int val);
int count_total(node tree);
int count_in(node tree);
int count_ex(node tree);
int height(node tree);
void mirror(node tree);
void delete_tree(node tree);
int main(){
	int i=0,val;
	node ptr;
	printf("-------------------********---------------\n");
	printf("-------------------MAIN MENU---------------\n");
	printf("1. Insert Element\n");
	printf("2. Preorder Traversal\n");
	printf("3. Inorder Traversal\n");
	printf("4. Postorder Traversal\n");
	printf("5. Find Smallest Element\n");
	printf("6. Find Largest Element\n");
	printf("7. Delete an Element\n");
	printf("8. Count the total number of nodes\n");
	printf("9. Count the total number of internal nodes\n");
	printf("10. Count the total number of external nodes\n");
	printf("11. Find Height of Tree\n");
	printf("12. Mirror the Tree\n");
	printf("13. Delete Tree\n");
	create_tree(tree);
	while(1){
		printf("\nEnter Your Choice : ");
		scanf("%d",&i);
		switch(i){
			case 1 :
				printf("Enter value : ");
				scanf("%d",&val);
				tree = insert_ele(tree,val);
				break;
			case 2:
				printf("Preorder Traversal : ");
				preorder_tra(tree);
				break;
			case 3:
				printf("Inorder Traversal : ");
				inorder_tra(tree);
				break;
			case 4:
				printf("Postrder Traversal : ");
				postorder_tra(tree);
				break;
			case 5:
				ptr = findSmallest(tree);
				printf("Smallest Element is : %d",ptr->data);
				break;
			case 6:
				ptr = findLargest(tree);
				printf("Largest Element is : %d",ptr->data);
				break;
			case 7:
				printf("Enter value : ");
				scanf("%d",&val);
				tree = delete_ele(tree,val);
				break;
			case 8:
				val = count_total(tree);
				printf("Total number of nodes : %d",val);
				break;
			case 9:
				val = count_in(tree);
				printf("Total number of internal nodes : %d",val);
				break;
			case 10:
				val = count_ex(tree);
				printf("Total number of external nodes : %d",val);
				break;
			case 11:
				val = height(tree);
				printf("height of tree : %d",val );
				break;
			case 12:
				mirror(tree);
				printf("Mirrored Tree");
				break;
			case 13:
				delete_tree(tree);
				printf("Tree deleted");
				break;
		}
	}
	return 0;
}
void create_tree(node tree){
	tree = NULL;
}
node insert_ele(node tree,int val){
	node ptr;
	ptr = (node)malloc(sizeof(node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree == NULL){
		tree = ptr;
		tree->left = NULL;
		tree->right = NULL;
	}
	else{
		node parentptr = NULL;
		node nodeptr = tree;
		while(nodeptr != NULL){
			parentptr = nodeptr;
			if(val<nodeptr->data)
				nodeptr = nodeptr->left;
			else
				nodeptr = nodeptr->right;
		}
		if (val<parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return tree;
}
void inorder_tra(node tree){
	node ptr = tree;
	if(ptr != NULL){
		inorder_tra(ptr->left);
		printf("%d ",ptr->data);
		inorder_tra(ptr->right);
	}
}
void preorder_tra(node tree){
	node ptr = tree;
	if(ptr != NULL){
		printf("%d ",ptr->data);
		preorder_tra(ptr->left);
		preorder_tra(ptr->right);
	}
}
void postorder_tra(node tree){
	node ptr = tree;
	if(ptr != NULL){
		postorder_tra(ptr->left);
		postorder_tra(ptr->right);
		printf("%d ",ptr->data);
	}
}
node findSmallest(node tree){
	node ptr = tree;
	if(ptr->left == NULL)
		return ptr;
	else
		return findSmallest(ptr->left);
}
node findLargest(node tree){
	node ptr = tree;
	if(ptr->right == NULL)
		return ptr;
	else
		return findSmallest(ptr->right);
}
node delete_ele(node tree,int val){
	if(tree == NULL){
		printf("Value not Found in Tree\n");
		return tree;
	}
	else if(val<tree->data){
		tree->left = delete_ele(tree->left,val);
	}
	else if(val>tree->data){
		tree->right = delete_ele(tree->right,val);
	}
	else{
		if(tree->left!=NULL && tree->right!=NULL){
			node temp = findSmallest(tree->right);
			tree->data = temp->data;
			tree->right = delete_ele(tree->right,temp->data);
		}
		else if(tree->right == NULL){
			node temp = tree->left;
			free(tree);
			return temp;
		}
		else{
			node temp = tree->right;
			free(tree);
			return  temp;
		}	
	}
}
int count_total(node tree){
	if(tree==NULL)
		return 0;
	else{
		return count_total(tree->left)+count_total(tree->right)+1;
	}
}
int count_in(node tree){
	if(tree->left==NULL && tree->right==NULL){
		return 0;
	}
	else{
		return count_in(tree->left)+count_in(tree->right)+1;
	}
}
int count_ex(node tree){
	if(tree == NULL)
		return 0;
	else if(tree->left==NULL && tree->right==NULL)
		return 1;
	else{
		return count_ex(tree->left)+count_ex(tree->right);
	}
}
int height(node tree){
	if(tree==NULL)
		return 0;
	int left = height(tree->left);
	int right = height(tree->right);
	if(left>=right)
		return  left+1;
	else
		return right+1;
}
void mirror(node tree){
	if(tree!= NULL){
		node temp = tree->left;
		tree->left = tree->right;
		tree->right = temp;
		mirror(tree->left);
		mirror(tree->right);
	}

}
void delete_tree(node tree){
	if(tree->left == NULL && tree->right==NULL)
		free(tree);
	else{
		delete_tree(tree->right);
		delete_tree(tree->left);
		tree=NULL;
	}
}
