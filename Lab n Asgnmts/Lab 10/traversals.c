#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;

node *create(int data)
{
    node * root = malloc(sizeof(node));
    root -> data = data;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}


void print_in(node * root)
{
    if(!root)
        return;
    
    print_in(root -> left);
    printf("%d --> ", root -> data);
    print_in(root -> right);
}

void print_pre(node *root)
{
    if(!root)
        return;
    
    printf("%d --> ", root -> data);
    print_pre(root -> left);
    print_pre(root -> right);
}

void print_post(node * root)
{
    if(!root)
        return;
    
    print_post(root -> left);
    print_post(root -> right);
    printf("%d --> ", root -> data);
}



// Level order
int height(node * root)
{
    if(!root)
        return 0;
    int lheight = height(root -> left);
    int rheight = height(root -> right);
    if(lheight > rheight)
        return (lheight + 1);
    return (rheight + 1);
}

void print_curr_lvl(node * root, int lvl)
{
    if(!root)
        return;
    if(lvl == 1)
        printf("%d --> ", root -> data);
    else if(lvl > 1)
    {
        print_curr_lvl(root -> left, lvl - 1);
        print_curr_lvl(root -> right, lvl - 1);
    }
}


void print_lvl_order(node * root)
{
    int h = height(root);
    for(int i = 1; i <= h; i++)
        print_curr_lvl(root, i);
}
//

// Morris traversal, pre without recursion
void Morris(node * root)
{
    while(root)
    {
        if(root -> left == NULL)
        {
            printf("%d --> ", root -> data);
            root = root -> right;
        }
        else
        {
            node * curr = root -> left;
            while(curr -> right && curr -> right != root)
                curr = curr -> right;
            
            if(curr -> right == root)
            {
                curr -> right = NULL;
                root = root -> right;
            }
            else
            {
                printf("%d --> ", root -> data);
                curr -> right = root;
                root = root -> left;
            }
        }
    }
}

// Zig zag traversal
void zigzag_traversal(node *root)
{
  if (root == NULL)
    return;

  node *stack[100];
  int top = -1;
  int left_to_right = 1; // Flag to indicate the direction

  stack[++top] = root;

  while (top != -1) 
  {
    node *temp[100];
    int temp_top = -1;

    while (top != -1) 
    {
      node *curr = stack[top--];
      printf("%d ", curr->data);

      if (left_to_right) 
      {
        if (curr->left != NULL)
          temp[++temp_top] = curr->left;
        
        if (curr->right != NULL)
          temp[++temp_top] = curr->right;
      } 
      else
      {
        if (curr->right != NULL)
          temp[++temp_top] = curr->right;
        
        if (curr->left != NULL)
          temp[++temp_top] = curr->left;
      }
    }

    for (int i = 0; i <= temp_top; i++)
      stack[++top] = temp[i];

    left_to_right = !left_to_right;
  }
}

void postorder_traversal(node *root)
{
  if (root == NULL)
    return;

  node *stack[100];
  int top = -1;
  node *prev = NULL;

  do 
  {
    while (root)
    {
      stack[++top] = root;
      root = root->left;
    }

    while (root == NULL && top != -1) 
    {
      root = stack[top];

      // Check if the right subtree is either NULL or has been visited
      if (root->right == NULL || root->right == prev) 
      {
        printf("%d ", root->data);
        top--;
        prev = root;
        root = NULL; // To move up the tree
      } 
      else
        root = root->right;
    }
  } while (top != -1);
}


void preorder_traversal(node *root)
{
  if (root == NULL)
    return;

  node *stack[100];
  int top = -1;

  stack[++top] = root;

  while (top != -1) 
  {
    node *curr = stack[top--];
    printf("%d ", curr->data);

    // Push the right child first, so it is processed after the left child
    if (curr->right != NULL)
      stack[++top] = curr->right;

    if (curr->left != NULL)
      stack[++top] = curr->left;
  }
}

void inorder_traversal(node *root)
{
  if (root == NULL)
    return;

  node *stack[100];
  int top = -1;
  node *curr = root;

  while (curr != NULL || top != -1) 
  {
    while (curr)
    {
      stack[++top] = curr;
      curr = curr->left;
    }

    curr = stack[top--];
    printf("%d ", curr->data);

    curr = curr->right;
  }
}

node * init(void)
{
    node * root = create(1);
    root -> left = create(2);
    root -> right = create(3);
    root -> left -> left = create(4);
    root -> left -> right = create(5);
    root -> right -> left = create(6);
    root -> right -> right = create(7);
    return root;
    
}
int main(void)
{
    node * root = init();
    Morris(root);
}
