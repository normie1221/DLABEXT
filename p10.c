#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
struct Node *createnode(int data){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct Node *insertnode(struct Node *root,int data){
    struct Node *newnode;
    if(root==NULL){
        newnode=createnode(data);
        root=newnode;
        return root;
    }
    if(root->data>data){
        root->left=insertnode(root->left,data);
    }
    if(root->data<data){
         root->right=insertnode(root->right,data);
    }
    return root;
}
int inorder(struct Node *root){
    if(root==NULL){
        return 0;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int preorder(struct Node *root){
    if(root==NULL){
        return 0;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int postorder(struct Node *root){
    if(root==NULL){
        return 0;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int searchnode(struct Node *root,int key){
    if(root==NULL){
        return 0;
    }
    else{
        if(root->data==key){
            return 1;
        }
        if(root->data>key){
            return searchnode(root->left,key);
        }
         if(root->data<key){
            return searchnode(root->right,key);
        }
    }
}
int main(){
    printf("ADITYA KUMAR\nUSN-1AY23CS012\n\n");
    int choice,n,val,i,key,result;
    struct Node *root=NULL;
    while(1){
    printf("\n1.Create BST\n2.Traverse BST(Inorder/Preorder/Postorder)");
    printf("\n3.Search KEY\n4.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("\nEnter number of Elements you want to Enter: ");
               scanf("%d",&n);
               for(i=1;i<=n;i++){
                printf("\nEnter Element %d:",i);
                scanf("%d",&val);
                root=insertnode(root,val);
               }
               break;
        case 2:printf("\nInorder: ");
               inorder(root);
               printf("\nPreorder: ");
               preorder(root);
               printf("\nPostorder: ");
               postorder(root);
               break;
        case 3:printf("\nEnter value which you want to search= ");
               scanf("%d",&key);
               result=searchnode(root,key);
               if(result==0){
                printf("\nKey not found.");
               }
               else{
                printf("\nKey is found.");
               }
               break;
        case 4:exit(0);
    }
    }
}