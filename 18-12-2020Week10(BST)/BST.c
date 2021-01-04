#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
	int data;
	struct BST *left,*right;
}node;

node *create(){
	node *newnode;
	int value;
	printf("Enter value: ");
	scanf("%d",&value);
	newnode = (node*)malloc(sizeof(node));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void insert(node *root,node *temp){
	if(temp->data < root->data){
		if(root->left == NULL)
			root->left = temp;
		else{
			insert(root->left,temp);
		}
	}
	if(temp->data > root->data){
		if(root->right == NULL)
			root->right = temp;
		else{
			insert(root->right,temp);
		}
	}
}
void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(node *root){
	if(root != NULL){
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

int main(int argc,char **argv){
	int choice;
	node *root=NULL,*temp;
	while(choice != 5){
		printf("\nEnter your choice: \n1)insert \n2)inorder \n3)preorder \n4)postorder \n5)display(by default preorder) \n6.exit \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:temp = create();
                    if(root == NULL)
                        root = temp;
                    else
                        insert(root,temp);
                    break;
			case 2:inorder(root);break;
			case 3:preorder(root);break;
			case 4:postorder(root);break;
			case 5:preorder(root);break;
			case 6:
			default:exit(0);
		}
	}
	return 0;
}
