/*
o/p:
Enter choice:
1.insert 2.search 3.inorder 
1
Enter data to insert:
34

Do you want to continue?
1
Enter choice:
1.insert 2.search 3.inorder 
1
Enter data to insert:
89

Do you want to continue?
1
Enter choice:
1.insert 2.search 3.inorder 
1
Enter data to insert:
58

Do you want to continue?
1
Enter choice:
1.insert 2.search 3.inorder 
2
Enter data to search:
89
Required data is found

Do you want to continue?
0


*/

#include<stdio.h>
#include<stdlib.h>

struct abc
{
  int data;
  struct abc *left,*right;
};

struct abc * insert(struct abc *,int);
struct abc * create(int);
struct abc *search(struct abc *,int);
struct abc *delete(struct abc *,int);
int inorder_s(struct abc *);
void inorder(struct abc *);

void main()
{
    int ch,d,y;
    struct abc *root=NULL;
    do
    {
    printf("Enter choice:\n");
    printf("1.insert 2.search 3.inorder 4.delete\n");
    scanf("%d",&ch);
    switch(ch)
    {
        
        case 1:
        printf("Enter data to insert:\n");
        scanf("%d",&d);
        root = insert(root,d);
        break;
        
        case 2:
        printf("Enter data to search:\n");
        scanf("%d",&d);
        search(root,d);
        break;
        
        case 3:
        printf("Tree traversal:\n");
        inorder(root);
        break;
        
        case 4:
        printf("Enter data to delete:\n");
        scanf("%d",&d);
        delete(root,d);
        printf("Data has been deleted\n");
        break;
        
    }
    printf("\nDo you want to continue?\n");
    scanf("%d",&y);
    }
    while(y==1);
    
}
struct abc * insert(struct abc *root,int d)
{
    if(root==NULL)
    {
        return create(d);
    }
    else if(d < root->data)
    {
        root->left = insert(root->left,d);
    }
    else 
    {
        root->right = insert(root->right,d);
    }
    return root;
}
struct abc * create(int d)
{
    struct abc *new;
    new = (struct abc *)malloc(sizeof(struct abc));
    new->data = d;
    new->left =NULL;
    new->right = NULL;
    
    return new;
}
void inorder(struct abc *root)
{
    
    if(root == NULL)
    {
        return;
    }
    else
    {
        if(root!=NULL)
        {
            inorder(root->left);
        }
        printf(" %d",root->data);
        inorder(root->right);
    }
}
struct abc *search(struct abc *root,int d)
{
    if(root == NULL)          //if no tree there
    {
       return root;
    }
    else if(d == root->data)     //if required data is itself a parent node
    {
        printf("Required data is found\n");
    }
    else if(d <root->data)          //if required data is smaller so it will find at left of parent node
    {
        root->left = search(root->left,d);
    }
    else if(d >root->data)                             //if required data is greater so it will find at right of parent node
    {
        root->right = search(root->right,d);
    }
    else
    {
    printf("oops no data found\n");
    }
}
struct abc * delete(struct abc *root,int d)
{
    
    if(root == NULL)
    {
        return root;
    }
    if(d<root->data)
    {
        root->left = delete(root->left,d);
    }
    else if(d>root->data)
    {
        root->right = delete(root->right,d);
    }
    else 
    {
        if(root->right == NULL)                 //only for node having one child
        {
            struct abc *temp;
            temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == NULL)
        {
            struct abc *temp;
            temp = root->right;
            free(root);
            return temp;
        }
        else
    {
        struct abc *temp;             //only for node having two childs
        temp = root->right;
        root->data = inorder_s(temp);
        root->right = delete(root->right,root->data);
    }
    return root;
    }
    
}
int inorder_s(struct abc *temp)
{
    while(temp && temp->left !=NULL)   //until we get inorder successor for given node
    temp = temp->left;
    return temp->data;  //in recursive call we should return the 1st node again to start again from that
    
}
