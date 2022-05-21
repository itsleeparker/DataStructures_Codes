//wap to imply binary binary search tree and display the inorder tree
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{   
    int data;
    struct bst *right;
    struct bst *left;
}tree;

tree *newnode;      //the scope of newnode should be global

tree *CreateNode(int data){

    newnode = (tree*)malloc(sizeof(tree));      //allocate memory to new node
    newnode->data = data;
    newnode->left = newnode->right = NULL;
}

void Insert(tree *root , int data){
    //insert the node accorduinglt 
    if(data < root->data){
        if(root->left == NULL){
            root->left = newnode;       //insert the node if the child node is empty
        }
        else{
            Insert(root->left , data);      //recurse the function if node is child ndoe is not empty
        }
    }
    else if(data > root->data){
        if(root->right == NULL){
            root->right = newnode;

        }
        else{
            Insert(root->right , data);
        }
    }
    else{
        printf("\nSomething Went Wrong");
        exit(0);
    }
}

void Inorder(tree *root){
    if(root != NULL){
        Inorder(root->left);
        printf("%3d=>" , root->data);
        Inorder(root->right);
    }
}

void Preorder(tree *root){
	if(root != NULL){
		printf("%3d=>" , root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(tree *root){
	if(root != NULL){
	
		Postorder(root->left);
		Postorder(root->right);
		printf("%3d=>", root->data);
	}	
}

int count(tree *root){
	if(root == NULL){
		return 0;
	}
	return(1+count(root->left)+count(root->right));
}


int countLeafNodes(tree *root){

	if(root == NULL)
		return 0;
	if(root->right == NULL && root->left == NULL)
		return 1;
	return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeaf(tree *root){
	if(root == NULL){
		return 0;
	}
	if(root->right ==NULL && root->left == NULL){
		return 0;
	}

	return (1+countNonLeaf(root->left)+countNonLeaf(root->right));
}

//MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    tree *root = NULL;
    int data , ch , Nodecount;
    //display menu to user
    printf("\n----BINARY SEARCH TREE----\n");
    do{
        printf("\n---MENU---\n");
        printf("\n[1]Insert");
        printf("\n[2]Inorder");
	printf("\n[3]Preorder");
	printf("\n[4]Postorder");
        printf("\n[5]Count Nodes");
	printf("\n[6]Count Leadt Nodes");
	printf("\n[7]Count Non Leaf Nodes");
	printf("\n[8]Exit");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            //Insert node
            printf("\nEnter data for node  : ");
            scanf("%d" , &data);
            CreateNode(data);   
            if(root == NULL){ 
                root = newnode;
            }
            else{
                Insert(root , data);
            }
            break;
        
        case 2:
            //Display tree inorder
            if(root == NULL){
                printf("\nNo data found Insert Data");
                break;
            }
            Inorder(root);
            break;
	
	case 3:
	    if(root == NULL){
		printf("\nNo data found Insert Data");
		break;
	    }
	    Preorder(root);
	    break;

	case 4:
	    	//postorder
		if(root == NULL){
			printf("\nNo data found Insert Data");
			break;
		}

		Postorder(root);
	    	break;
	case 5:
		//count 
		if(root == NULL){
			 printf("\nNo data found Insert Data");
                        break;  
		}
		Nodecount =  count(root);
		printf("\nThe Total number of nodes are %d" , Nodecount);
		break;

	case 6:
		//count leaf nodes
		if(root == NULL){
                 printf("\nNo data found Insert Data");
                 break;
                }
		Nodecount = countLeafNodes(root);
		printf("\nThe Total number of leaf nodes are %d" , Nodecount);
		break;

	case 7:
		//count non leaf nodes
		
		if(root == NULL){
			printf("\nNo Data found Insert Data");
			break;
		}
		Nodecount = countNonLeaf(root);
		printf("\nThe Total number of Non Leaf nodes are %d \n" , Nodecount);
		break;
        case 8:
            //exit
            break;
        
        default:
            printf("\nEnter valid choice !!\n");
            break;
        }
    }while(ch!= 8);
    printf("\n----THANK YOU USE AGIAN----\n");    
    return 0;
}
